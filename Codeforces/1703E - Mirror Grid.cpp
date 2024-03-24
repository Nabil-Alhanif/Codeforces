#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;
 
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

    int t;
    cin >> t;

    while (t--) {
        char c;
        int n, ans = 0, tmp;
        cin >> n;

        vector<vector<int>> board(n, vector<int>(n));
        for (auto &row:board) {
            for (auto &col:row) {
                cin >> c;
                col = (c - '0');
            }
        }

        int mid = (n + 1) / 2;
        int idx = 0;
        int tot = mid * mid;

        //cout << "mid, tot " << mid << " " << tot << "\n";

        vector<set<pair<int, int>>> dp(tot);
        map<pair<int, int>, bool> exist;

        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                if (exist[{i, j}])
                    continue;

                dp[idx].insert({i, j});
                dp[idx].insert({j, n - 1 - i});
                dp[idx].insert({n - 1 - i, n - 1 - j});
                dp[idx].insert({n - 1 - j, i});

                /*
                dp[idx].insert({j, i});
                dp[idx].insert({j, n - 1 - i});
                dp[idx].insert({n - 1 - j, n - 1 - i});
                dp[idx].insert({n - 1 - j, i});
                */

                tmp = 0;
                for (auto k:dp[idx]) {
                    exist[k] = 1;
                    //cout << board[k.fi][k.se] << " " << k.fi << " " << k.se << " fise\n";
                    tmp += board[k.fi][k.se];
                }
                ans += min(tmp, static_cast<int>(dp[idx].size()) - tmp);

                idx++;
                //cout << "\n\n";
            }
        }

        cout << ans << "\n";
    }
}
