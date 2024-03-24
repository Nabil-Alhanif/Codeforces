#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long double ld;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class SegTree {
    public:
        ll size;
        vector<ll> tree;
        vector<ll> lazy;

        SegTree(ll n)
        {
            this->size = n + 1;
            this->tree.resize(this->size * 4);
            this->lazy.resize(this->size * 4);
        }

        void update(ll vertex, ll left, ll right, ll left_bound, ll right_bound, ll delta)
        {
            if (left > right)
                return;

            ll cnt = right_bound - left_bound + 1;
            if (this->lazy[vertex] != 0) {
                this->tree[vertex] += cnt * this->lazy[vertex];
                if (left_bound != right_bound) {
                    this->lazy[vertex * 2] += this->lazy[vertex];
                    this->lazy[vertex * 2 + 1] += this->lazy[vertex];
                }
                this->lazy[vertex] = 0;
            }

            if ((left == left_bound) && (right == right_bound)) {
                this->tree[vertex] += cnt * delta;
                if (left_bound != right_bound) {
                    this->lazy[vertex * 2] += delta;
                    this->lazy[vertex * 2 + 1] += delta;
                }
                return;
            }

            ll mid = (left_bound + right_bound) / 2;
            if (right <= mid)
                update(vertex * 2, left, right, left_bound, mid, delta);
            else if (left > mid)
                update (vertex * 2 + 1, left, right, mid + 1, right_bound, delta);
            else {
                update(vertex * 2, left, mid, left_bound, mid, delta);
                update(vertex * 2 + 1, mid + 1, right, mid + 1, right_bound, delta);
            }
            this->tree[vertex] = this->tree[vertex * 2] + this->tree[vertex * 2 + 1];
        }

        ll query(ll vertex, ll left, ll right, ll left_bound, ll right_bound)
        {
            if (left > right)
                return 0;

            ll cnt = right_bound - left_bound + 1;
            if (this->lazy[vertex] != 0) {
                this->tree[vertex] += cnt * this->lazy[vertex];
                if (left_bound != right_bound) {
                    this->lazy[vertex * 2] += this->lazy[vertex];
                    this->lazy[vertex * 2 + 1] += this->lazy[vertex];
                }
                this->lazy[vertex] = 0;
            }


            if ((left == left_bound) && (right == right_bound))
                return this->tree[vertex];

            ll mid = (left_bound + right_bound) / 2;
            if (right <= mid)
                return query(vertex * 2, left, right, left_bound, mid);
            else if (left > mid)
                return query(vertex * 2 + 1, left, right, mid + 1, right_bound);
            else {
                ll left_side = query(vertex * 2, left, mid, left_bound, mid);
                ll right_side = query(vertex * 2 + 1, mid + 1, right, mid + 1, right_bound);
                return (left_side + right_side);
            }
        }
};

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, c;
        cin >> n >> c;

        SegTree tree(n);

        ll ty, p, q, v;
        while (c--) {
            cin >> ty >> p >> q;

            if (ty == 0) {
                cin >> v;
                tree.update(1, p, q, 1, n, v);
            }
            else cout << tree.query(1, p, q, 1, n) << "\n";

            /*
            for (int i = 1; i < tree.size * 4; i++)
                cout << i << " " << tree.tree[i] << " " << tree.lazy[i] << "\n";
            */
        }
    }
}
