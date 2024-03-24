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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, q, h, w, hb, wb;
        cin >> n >> q;

        vector<vector<ll>> arr(1001, vector<ll>(1001));
        for (int i = 0; i < n; i++) {
            cin >> h >> w;
            arr[h][w] += (h * w);
        }

        vector<vector<ll>> dp(1001, vector<ll>(1001));
        for (int i = 1; i < 1001; i++) {
            for (int j = 1; j < 1001; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }

        /*
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << dp[i][j] << " ";
            cout << "\n";
        }
        */

        while (q--) {
            cin >> h >> w >> hb >> wb;
            ll ans = dp[hb - 1][wb - 1] - dp[h][wb - 1] - dp[hb - 1][w] + dp[h][w];
            cout << ans << "\n";
        }
    }
}
