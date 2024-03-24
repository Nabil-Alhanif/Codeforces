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


class SegTreeMin
{
    public:
        ll size;
        vector<ll> arr;
        vector<ll> tree;

        SegTreeMin(ll n)
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
                tree[vertex] = min(tree[vertex * 2], tree[vertex * 2 + 1]);
            }
        }

        ll get(ll vertex, ll left_search, ll right_search, ll left_bound, ll right_bound)
        {
            if (left_bound > right_bound)
                return -1;

            if ((left_search == left_bound) && (right_search == right_bound))
                return tree[vertex];

            ll mid = (left_bound + right_bound) / 2;
            if (right_search <= mid)
                return get(vertex * 2, left_search, right_search, left_bound, mid);
            else if (left_search > mid)
                return get(vertex * 2 + 1, left_search, right_search, mid + 1, right_bound);
            else {
                ll left_side = get(vertex * 2, left_search, mid, left_bound, mid);
                ll right_side = get(vertex * 2 + 1, mid + 1, right_search, mid + 1, right_bound);
                return min(left_side, right_side);
            }
        }
};

class SegTreeMax
{
    public:
        ll size;
        vector<ll> arr;
        vector<ll> tree;

        SegTreeMax(ll n)
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
                tree[vertex] = max(tree[vertex * 2], tree[vertex * 2 + 1]);
            }
        }

        ll get(ll vertex, ll left_search, ll right_search, ll left_bound, ll right_bound)
        {
            if (left_bound > right_bound)
                return -1;

            if ((left_search == left_bound) && (right_search == right_bound))
                return tree[vertex];

            ll mid = (left_bound + right_bound) / 2;
            if (right_search <= mid)
                return get(vertex * 2, left_search, right_search, left_bound, mid);
            else if (left_search > mid)
                return get(vertex * 2 + 1, left_search, right_search, mid + 1, right_bound);
            else {
                ll left_side = get(vertex * 2, left_search, mid, left_bound, mid);
                ll right_side = get(vertex * 2 + 1, mid + 1, right_search, mid + 1, right_bound);
                return max(left_side, right_side);
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    SegTreeMax a(n);
    SegTreeMin b(n);

    for (int i = 0; i < n; i++)
        cin >> a.arr[i];
    a.build(1, 0, n - 1);

    for (int i = 0; i < n; i++)
        cin >> b.arr[i];
    b.build(1, 0, n - 1);

        ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll low_idx = -1, hi_idx = -2;

        // Cari lower bound nya dulu
        for (ll l = i, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            ll max_val = a.get(1, i, mid, 0, n - 1);
            ll min_val = b.get(1, i, mid, 0, n - 1);
            ll dif = max_val - min_val;

            if (dif < 0)
                l = mid + 1;
            else if (dif == 0) {
                low_idx = mid;
                r = mid - 1;
            }
            else r = mid - 1;
        }

        // Cari upper bound
        for (ll l = i, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            ll max_val = a.get(1, i, mid, 0, n - 1);
            ll min_val = b.get(1, i, mid, 0, n - 1);
            ll dif = max_val - min_val;

            if (dif < 0)
                l = mid + 1;
            else if (dif == 0) {
                hi_idx = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        //cout << i << " " << low_idx << " " << hi_idx << "\n";

        ans += (hi_idx - low_idx + 1);
    }

    cout << ans << "\n";
}
