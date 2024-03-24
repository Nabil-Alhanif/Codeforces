#include <algorithm>
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

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for (auto &i:board) {
        for (auto &j:i)
            cin >> j;
    }

    ll cnt = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((board[i][j] == '.') && !vis[i][j]) {
                queue<pair<ll, ll>> q;
                cnt++;

                vis[i][j] = 1;
                q.push({i, j});
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (r - 1 >= 0) {
                        if ((!vis[r - 1][c]) && (board[r - 1][c] == '.')) {
                            q.push({r - 1, c});
                            vis[r - 1][c] = 1;
                        }
                    }
                    if (r + 1 < n) {
                        if ((!vis[r + 1][c]) && (board[r + 1][c] == '.')) {
                            q.push({r + 1, c});
                            vis[r + 1][c] = 1;
                        }
                    }

                    if (c - 1 >= 0) {
                        if ((!vis[r][c - 1]) && (board[r][c - 1] == '.')) {
                            q.push({r, c - 1});
                            vis[r][c - 1] = 1;
                        }
                    }
                    if(c + 1 < m) {
                        if ((!vis[r][c + 1]) && (board[r][c + 1] == '.')) {
                            q.push({r, c + 1});
                            vis[r][c + 1] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << "\n";
}
