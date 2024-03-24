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


vector<ull> dp;

void construct(ull len, ull cnt, ull val)
{
    if (len == 19) {
        if ((cnt <= 3) && (val != 0)) {
            dp.push_back(val);
            //cout << "val: " << val << "\n";
        }
        return;
    }

    //cout << len << " " << cnt << " " << val << "\n";

    if (cnt > 3)
        return;

    construct(len + 1, cnt, val * 10);

    for (int i = 1; i <= 9; i++)
        construct(len + 1, cnt + 1, val * 10 + i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    construct(0, 0, 0);
    sort(dp.begin(), dp.end());
    ll size = dp.size();

    /*
    for (int i = 0; i < 10; i++)
        cout << dp[i] << " ";
    cout << "\n";
    */

    ull t;
    cin >> t;

    while (t--) {
        ull x, y, ans = 0;
        cin >> x >> y;

        ll low_bound = -1;
        for (ll l = 0, r = size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (dp[mid] < x)
                l = mid + 1;
            else {
                low_bound = mid;
                r = mid - 1;
            }
        }

        ll hi_bound = -2;
        for (ll l = 0, r = size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (dp[mid] <= y) {
                hi_bound = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        /*
        cout << hi_bound << " " << low_bound << "\n";
        cout << dp[hi_bound] << " " << dp[low_bound] << "\n";
        */

        ans = (hi_bound - low_bound) + 1;
        cout << ans << "\n";
    }
}
