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

const ll MOD = 998244353, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> board(n, vector<ll>(m));
        for (auto &i:board) {
            for (auto &j:i)
                cin >> j;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll cnt = 0;

                // Tambahin diagonal ke kiri atas
                for (int y = i, x = j; (y >= 0) && (x >= 0); x--, y--)
                    cnt += board[y][x];

                // Tambahin diagonal ke kanan atas
                for (int y = i, x = j; (y >= 0) && (x < m); x++, y--)
                    cnt += board[y][x];

                // Tambahin diagonal ke kiri bawah
                for (int y = i, x = j; (y < n) && (x >= 0); x--, y++)
                    cnt += board[y][x];

                // Tambahin diagonal ke kanan bawah
                for (int y = i, x = j; (y < n) && (x < m); x++, y++)
                    cnt += board[y][x];

                cnt -= (board[i][j] * 3);
                ans = max(ans, cnt);
            }
        }
        cout << ans << "\n";
    }
}
