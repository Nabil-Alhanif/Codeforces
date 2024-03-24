#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


struct segment
{
    ll size;
    ll l;
    ll r;
};

bool comp(segment &a, segment &b)
{
    if (a.size == b.size)
        return (a.l > b.l);
    return (a.size < b.size);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> ans(n + 1);

        priority_queue<segment, vector<segment>, decltype(&comp)> pq(comp);
        pq.push({.size = n, .l = 1, .r = n});

        ll cnt = 1;
        while (!pq.empty()) {
            segment cur = pq.top();
            pq.pop();

            if (cur.l > cur.r)
                continue;

            if (cur.size % 2) {
                ll mid = (cur.l + cur.r) / 2;
                ans[mid] = cnt;
                if (cur.size != 1) {
                    pq.push({.size = mid - cur.l, .l = cur.l, .r = mid - 1});
                    pq.push({.size = cur.r - mid, .l = mid + 1, .r = cur.r});
                }
            }
            else {
                ll mid = (cur.l + cur.r - 1) / 2;
                ans[mid] = cnt;
                pq.push({.size = mid - cur.l, .l = cur.l, .r = mid - 1});
                pq.push({.size = cur.r - mid, .l = mid + 1, .r = cur.r});
            }

            cnt++;
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
