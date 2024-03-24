#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll LIM = 1e8;


struct tet
{
    ll r;
    ll c;
    ll rot;
};

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
    vector<vector<char>> b2 = board;

    vector<tet> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '1')
                continue;

            bool atas = ((i - 1 >= 0) ? (board[i - 1][j] == '0') : 0);
            bool bawah = ((i + 1 < n) ? (board[i + 1][j] == '0') : 0);
            bool kiri = ((j - 1 >= 0) ? (board[i][j - 1] == '0') : 0);
            bool kanan = ((j + 1 < m) ? (board[i][j + 1] == '0') : 0);

            if (atas && kiri && kanan)
                pos.push_back({i, j, 3});
            if (bawah && kiri && kanan)
                pos.push_back({i, j, 1});
            if (kiri && atas && bawah)
                pos.push_back({i, j, 2});
            if (kanan && atas && bawah)
                pos.push_back({i, j, 4});
        }
    }

    /*
    cout << "POS: \n";
    for (auto i:pos)
        cout << i.r << " " << i.c << " " << i.rot << "\n";
    */

    shuffle(pos.begin(), pos.end(), mt19937(random_device()()));

    vector<tet> ans;
    for (auto i:pos) {
        if (b2[i.r][i.c] == '1')
            continue;

        bool atas = ((i.r - 1 >= 0) ? (b2[i.r - 1][i.c] == '0') : 0);
        bool bawah = ((i.r + 1 < n) ? (b2[i.r + 1][i.c] == '0') : 0);
        bool kiri = ((i.c - 1 >= 0) ? (b2[i.r][i.c - 1] == '0') : 0);
        bool kanan = ((i.c + 1 < m) ? (b2[i.r][i.c + 1] == '0') : 0);

        if (i.rot == 1) {
            if (bawah && kanan && kiri) {
                ans.push_back(i);
                b2[i.r][i.c] = '1';
                b2[i.r + 1][i.c] = '1';
                b2[i.r][i.c - 1] = '1';
                b2[i.r][i.c + 1] = '1';
            }
        }
        else if (i.rot == 2) {
            if (kiri && atas && bawah) {
                ans.push_back(i);
                b2[i.r][i.c] = '1';
                b2[i.r - 1][i.c] = '1';
                b2[i.r + 1][i.c] = '1';
                b2[i.r][i.c - 1] = '1';
            }
        }
        else if (i.rot == 3) {
            if (atas && kanan && kiri) {
                ans.push_back(i);
                b2[i.r][i.c] = '1';
                b2[i.r - 1][i.c] = '1';
                b2[i.r][i.c - 1] = '1';
                b2[i.r][i.c + 1] = '1';
            }
        }
        else {
            if (kanan && atas && bawah) {
                ans.push_back(i);
                b2[i.r][i.c] = '1';
                b2[i.r - 1][i.c] = '1';
                b2[i.r + 1][i.c] = '1';
                b2[i.r][i.c + 1] = '1';
            }
        }

        /*
        cout << "\n\n";
        for (auto i:b2) {
            for (auto j:i)
                cout << j;
            cout << "\n";
        }
        */
    }

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i.r + 1 << " " << i.c + 1 << " " << i.rot << "\n";
}
