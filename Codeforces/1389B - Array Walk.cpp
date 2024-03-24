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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k, z;
        cin >> n >> k >> z;

        vector<ll> arr(n);
        vector<vector<pair<ll, ll>>> dp(k + 1, vector<pair<ll, ll>>(z + 1)); // Cur val, cur idx
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        dp[0][0] = {arr[0], 0};
        for (int i = 1; i <= k; i++) {
            auto [ls_val, ls_idx] = dp[i - 1][0];
            dp[i][0] = {ls_val + arr[ls_idx + 1], ls_idx + 1};
        }

        for (int i = 1; i <= z; i++) {
            dp[0][0] = {arr[0], 0};
            for (int j = 1; j <= k; j++) {
                auto [ls_val, ls_idx] = dp[j - 1][i];
                dp[j][i] = {ls_val + arr[ls_idx + 1], ls_idx + 1};

                tie(ls_val, ls_idx) = dp[j - 1][i - 1];
                if (ls_idx - 1 >= 0) {
                    if (ls_val + arr[ls_idx - 1] >= dp[j][i].fi)
                        dp[j][i] = {ls_val + arr[ls_idx - 1], ls_idx - 1};
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i <= z; i++)
            ans = max(ans, dp[k][i].fi);
        cout << ans << "\n";
    }
}
