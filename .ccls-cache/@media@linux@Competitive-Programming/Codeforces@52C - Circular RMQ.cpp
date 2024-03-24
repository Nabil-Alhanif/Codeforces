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

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class SegTree
{
    public:
        ll size;
        vector<ll> arr;
        vector<ll> tree;
        vector<ll> lazy;

        SegTree(ll n)
        {
            this->size = n;
            this->arr.resize(n);
            this->tree.resize(n * 4 + 4);
            this->lazy.resize(n * 4 + 4);
        }

        void build(ll node, ll left, ll right)
        {
            if (left > right)
                return;

            if (left == right) {
                this->tree[node] = this->arr[left];
                return;
            }

            ll mid = (left + right) / 2;
            build(node * 2, left, mid);
            build(node * 2 + 1, mid + 1, right);

            this->tree[node] = min(this->tree[node * 2], this->tree[node * 2 + 1]);
        }

        void update(ll node, ll left, ll right, ll start, ll end, ll delta)
        {
            if (start > end)
                return;

            if (this->lazy[node] != 0) {
                this->tree[node] += this->lazy[node];
                if (left != right) {
                    this->lazy[node * 2] += this->lazy[node];
                    this->lazy[node * 2 + 1] += this->lazy[node];
                }
                this->lazy[node] = 0;
            }

            if ((start > right) || (end < left))
                return;

            if ((left >= start) && (right <= end)) {
                this->tree[node] += delta;
                if (left != right) {
                    this->lazy[node * 2] += delta;
                    this->lazy[node * 2 + 1] += delta;
                }
                return;
            }

            ll mid = (left + right) / 2;
            update(node * 2, left, mid, start, end, delta);
            update(node * 2 + 1, mid + 1, right, start, end, delta);
            this->tree[node] = min(this->tree[node * 2], this->tree[node * 2 + 1]);
        }

        ll get(ll node, ll left, ll right, ll start, ll end)
        {
            if (left > right)
                return 0;

            if (this->lazy[node] != 0) {
                this->tree[node] += this->lazy[node];
                if (left != right) {
                    this->lazy[node * 2] += this->lazy[node];
                    this->lazy[node * 2 + 1] += this->lazy[node];
                }
                this->lazy[node] = 0;
            }

            if ((start == left) && (end == right))
                return this->tree[node];

            ll mid = (left + right) / 2;
            if (end <= mid)
                return get(node * 2, left, mid, start, end);
            else if (start > mid)
                return get(node * 2 + 1, mid + 1, right, start, end);

            ll left_side = get(node * 2, left, mid, start, mid);
            ll right_side = get(node * 2 + 1, mid + 1, right, mid + 1, end);
            return min(left_side, right_side);
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    SegTree segs(n);
    for (int i = 0; i < n; i++)
        cin >> segs.arr[i];
    segs.build(1, 0, n - 1);

    ll q;
    cin >> q;

    string s;
    getline(cin, s);

    while (q--) {
        getline(cin, s);
        stringstream ss(s);
        string nt;

        vector<ll> parsed;
        while (ss >> nt)
            parsed.push_back(stoi(nt));

        if (parsed.size() == 2) {
            ll l = parsed[0], r = parsed[1];
            if (l <= r)
                cout << segs.get(1, 0, n - 1, l, r) << "\n";
            else {
                ll left = segs.get(1, 0, n - 1, 0, r);
                ll right = segs.get(1, 0, n - 1, l, n - 1);
                cout << min(left, right) << "\n";
            }
        }
        else {
            ll l = parsed[0], r = parsed[1] , v = parsed[2];
            if (l <= r) {
                segs.update(1, 0, n - 1, l, r, v);
            }
            else {
                segs.update(1, 0, n - 1, 0, r, v);
                segs.update(1, 0, n - 1, l, n - 1, v);
            }
        }

        /*
        for (auto i:segs.tree)
            cout << i << " ";
        cout << "\n";
        */
    }
}
