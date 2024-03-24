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

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(m + 1, INF)));
    vector<ll> tree_color(n);
    for (auto &i:tree_color)
        cin >> i;

    vector<vector<ll>> cost(n, vector<ll>(m + 1));
    for (auto &i:cost) {
        for (int j = 1; j <= m; j++)
            cin >> i[j];
    }

    if (tree_color[0] != 0)
        dp[0][1][tree_color[0]] = 0;
    else {
        for (int i = 1; i <= m; i++)
            dp[0][1][i] = cost[0][i];
    }

    // Kak Sidiq plis pala saya puyeng sama nih DP satu :sob:
    for (int tree_idx = 1; tree_idx < n; tree_idx++) {
        for (int beauty = 1; beauty <= k; beauty++) {
            // Dah berwarna
            if (tree_color[tree_idx] != 0) {
                dp[tree_idx][beauty][tree_color[tree_idx]] = min(dp[tree_idx][beauty][tree_color[tree_idx]], dp[tree_idx - 1][beauty][tree_color[tree_idx]]);

                for (int warna_sebelum = 1; warna_sebelum <= m; warna_sebelum++)
                    if (warna_sebelum != tree_color[tree_idx])
                        dp[tree_idx][beauty][tree_color[tree_idx]] = min(dp[tree_idx][beauty][tree_color[tree_idx]], dp[tree_idx - 1][beauty - 1][warna_sebelum]);
            }
            else {
                for (int warna_sekarang = 1; warna_sekarang <= m; warna_sekarang++) {
                    dp[tree_idx][beauty][warna_sekarang] = min(dp[tree_idx][beauty][warna_sekarang], dp[tree_idx - 1][beauty][warna_sekarang] + cost[tree_idx][warna_sekarang]);
                    for (int warna_sebelum = 1; warna_sebelum <= m; warna_sebelum++) {
                        if (warna_sebelum != warna_sekarang)
                            dp[tree_idx][beauty][warna_sekarang] = min(dp[tree_idx][beauty][warna_sekarang], dp[tree_idx - 1][beauty - 1][warna_sebelum] + cost[tree_idx][warna_sekarang]);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int warna_sekarang = 1; warna_sekarang <= m; warna_sekarang++)
        ans = min(ans, dp[n - 1][k][warna_sekarang]);
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}
