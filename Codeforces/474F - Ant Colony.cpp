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


class SegTreeGCD
{
    public:
        ll size;
        vector<ll> tree;
        vector<ll> arr;

        SegTreeGCD(ll n)
        {
            this->size = n;
            this->arr.resize(n);
            this->tree.resize(n * 4 + 1);
        }

        void build(ll vertex, ll left_bound, ll right_bound)
        {
            if (left_bound == right_bound)
                tree[vertex] = arr[left_bound];
            else {
                ll mid = (left_bound + right_bound) / 2;
                build(vertex * 2, left_bound, mid);
                build(vertex * 2 + 1, mid + 1, right_bound);

                tree[vertex] = gcd(tree[vertex * 2], tree[vertex * 2 + 1]);
            }
        }

        ll get(ll vertex, ll left_bound, ll right_bound, ll left_search, ll right_search)
        {
            if (left_search > right_search)
                return 0;

            if ((left_search == left_bound) && (right_search == right_bound))
                return tree[vertex];

            ll mid = (left_search + right_search) / 2;
            if (right_bound <= mid) {
                return get(vertex * 2, left_bound, right_bound, left_search, mid);
            }
            else if (left_bound > mid) {
                return get(vertex * 2 + 1, left_bound, right_bound, mid + 1, right_search);
            }
            else {
                ll left_side = get(vertex * 2, left_bound, mid, left_search, mid);
                ll right_side = get(vertex * 2 + 1, mid + 1, right_bound, mid + 1, right_search);
                return gcd(left_side, right_side);
            }
        }
};

class SegTreeFull
{
    public:
        ll size;
        vector<map<ll, ll>> tree;
        vector<ll> arr;

        SegTreeFull(ll n)
        {
            this->size = n;
            this->arr.resize(n);
            this->tree.resize(n * 4 + 1);
        }

        void build(ll vertex, ll left_bound, ll right_bound)
        {
            if (left_bound == right_bound)
                tree[vertex][arr[left_bound]]++;
            else {
                ll mid = (left_bound + right_bound) / 2;
                build(vertex * 2, left_bound, mid);
                build(vertex * 2 + 1, mid + 1, right_bound);

                tree[vertex] = tree[vertex * 2];
                for (auto i:tree[vertex * 2 + 1])
                    tree[vertex][i.fi] += i.se;
            }

            /*
            cout << vertex << ": ";
            for (auto i:tree[vertex])
                cout << i << " ";
            cout << "\n";
            */
        }

        ll get(ll vertex, ll left_bound, ll right_bound, ll left_search, ll right_search, ll target)
        {
            if (left_search > right_search)
                return 0;

            if ((left_search == left_bound) && (right_search == right_bound))
                return tree[vertex][target];

            ll mid = (left_search + right_search) / 2;
            if (right_bound <= mid)
                return get(vertex * 2, left_bound, right_bound, left_search, mid, target);
            else if (left_bound > mid)
                return get(vertex * 2 + 1, left_bound, right_bound, mid + 1, right_search, target);
            else {
                ll left_side = get(vertex * 2, left_bound, mid, left_search, mid, target);
                ll right_side = get(vertex * 2 + 1, mid + 1, right_bound, mid + 1, right_search, target);
                return (left_side + right_side);
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    SegTreeGCD tree(n);
    SegTreeFull fulltree(n);

    for (int i = 0; i < n; i++) {
        cin >> tree.arr[i];
        fulltree.arr[i] = tree.arr[i];
    }

    tree.build(1, 0, n - 1);
    fulltree.build(1, 0, n - 1);

    //cout << "BUILD\n";

    ll t;
    cin >> t;

    ll l, r;
    while (t--) {
        cin >> l >> r;
        l--, r--;
        ll gcd_val = tree.get(1, l, r, 0, n - 1);
        ll ans = fulltree.get(1, l, r, 0, n - 1, gcd_val);

        ans = r - l + 1 - ans;
        cout << ans << "\n";
    }
}
