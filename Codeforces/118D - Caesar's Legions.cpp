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

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<vector<ll>>> dp(n1 + 1, vector<vector<ll>>(n2 + 1, vector<ll>(2)));

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 1; k <= k1; k++) {
                if (i >= k) {
                    dp[i][j][0] += dp[i - k][j][1];
                    dp[i][j][0] %= MOD;
                }
            }

            for (int k = 1; k <= k2; k++) {
                if (j >= k) {
                    dp[i][j][1] += dp[i][j - k][0];
                    dp[i][j][1] %= MOD;
                }
            }
        }
    }

    ll ans = dp[n1][n2][0] + dp[n1][n2][1];
    ans %= MOD;

    cout << ans << "\n";
}
