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
        ll n, m, cur_col = 1;
        cin >> n >> m;

        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        }

        bool flag = 1;

        vector<vector<pair<ll, ll>>> segs;
        vector<vector<ll>> color(n, vector<ll>(m));

        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '*') {

                    // Cek dulu diagonal nya ada yang nempel apa kagak
                    bool atas_aman = (i - 1 >= 0);
                    bool bawah_aman = (i + 1 < n);
                    bool kiri_aman = (j - 1 >= 0);
                    bool kanan_aman = (j + 1 < m);

                    if (atas_aman && kiri_aman)
                        flag &= !((board[i - 1][j - 1] == '*') && (color[i - 1][j - 1] != color[i][j]));
                    if (atas_aman && kanan_aman)
                        flag &= !((board[i - 1][j + 1] == '*') && (color[i - 1][j + 1] != color[i][j]));
                    if (bawah_aman && kiri_aman)
                        flag &= !((board[i + 1][j - 1] == '*') && (color[i + 1][j - 1] != color[i][j]));
                    if (bawah_aman && kanan_aman)
                        flag &= !((board[i + 1][j + 1] == '*') && (color[i + 1][j + 1] != color[i][j]));

                    if (!vis[i][j]) {
                        vis[i][j] = 1;

                        vector<pair<ll, ll>> cur_seg;
                        cur_seg.push_back({i, j});

                        queue<pair<ll, ll>> q;
                        q.push({i, j});

                        while (!q.empty()) {
                            auto [r, c] = q.front();
                            q.pop();

                            color[r][c] = cur_col;

                            // Atas
                            if (r - 1 >= 0) {
                                if (!vis[r - 1][c] && (board[r - 1][c] == '*')) {
                                    vis[r - 1][c] = 1;
                                    cur_seg.push_back({r - 1, c});
                                    q.push({r - 1, c});
                                }
                            }

                            // bawah
                            if (r + 1 < n) {
                                if (!vis[r + 1][c] && (board[r + 1][c] == '*')) {
                                    vis[r + 1][c] = 1;
                                    cur_seg.push_back({r + 1, c});
                                    q.push({r + 1, c});
                                }
                            }

                            // kanan
                            if (c + 1 < m) {
                                if (!vis[r][c + 1] && (board[r][c + 1] == '*')) {
                                    vis[r][c + 1] = 1;
                                    cur_seg.push_back({r, c + 1});
                                    q.push({r, c + 1});
                                }
                            }

                            // kiri
                            if (c - 1 >= 0) {
                                if (!vis[r][c - 1] && (board[r][c - 1] == '*')) {
                                    vis[r][c - 1] = 1;
                                    cur_seg.push_back({r, c - 1});
                                    q.push({r, c - 1});
                                }
                            }
                        }

                        if (!cur_seg.empty())
                            segs.push_back(cur_seg);
                    }

                    cur_col++;
                }
            }
        }

        ll size = segs.size();
        for (int i = 0; i < size; i++) {
            /*
            for (auto j:segs[i])
                cout << j.fi << " " << j.se << "\n";
            */

            // Cek dia ukurannya 3 apa kagak
            flag &= (segs[i].size() == 3);

            // Cek mereka sebaris apa kagak
            // Kalau sebaris ya artinya no
            flag &= !((segs[i][0].fi == segs[i][1].fi) && (segs[i][0].fi == segs[i][2].fi));
            flag &= !((segs[i][0].se == segs[i][1].se) && (segs[i][0].se == segs[i][2].se));
        }

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << color[i][j];
            cout << "\n";
        }
        */

        cout << (flag ? "YES\n" : "NO\n");
    }
}
