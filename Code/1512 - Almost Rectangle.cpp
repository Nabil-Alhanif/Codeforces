#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        pair<int, int> coor_satu = {-1, -1}; // row, col
        pair<int, int> coor_dua;

        vector<vector<char>> field(n, vector<char>(n));
        for (auto &row:field)
        {
            for (auto &col:row)
            {
                cin >> col;

                if (col == '*')
                {
                    if (coor_satu.first == -1)
                        coor_satu = {(&row - &field[0]), (&col - &row[0])};
                    else
                        coor_dua = {(&row - &field[0]), (&col - &row[0])};
                }
            }
        }

        // Cek apakah mereka segaris
        // Row sama
        if (coor_satu.first == coor_dua.first)
        {
            // Kalau row nya paling atas, artinya turun sekali
            if (coor_satu.first == 0)
            {
                field[coor_satu.first + 1][coor_satu.second] = '*';
                field[coor_dua.first + 1][coor_dua.second] = '*';
            }
            else // Selain itu, naik aja sekali
            {
                field[coor_satu.first - 1][coor_satu.second] = '*';
                field[coor_dua.first - 1][coor_dua.second] = '*';
            }
        }
        else if (coor_satu.second == coor_dua.second) // Col sama
        {
            // Kalau col nya paling kiri, artinya ke kanan aja
            if (coor_satu.second == 0)
            {
                field[coor_satu.first][coor_satu.second + 1] = '*';
                field[coor_dua.first][coor_dua.second + 1] = '*';
            }
            else // Selain itu ke kiri aja
            {
                field[coor_satu.first][coor_satu.second - 1] = '*';
                field[coor_dua.first][coor_dua.second - 1] = '*';
            }
        }
        else // Artinya mereka saling bersebrangan secara diagonal
        {
            field[coor_satu.first][coor_dua.second] = '*';
            field[coor_dua.first][coor_satu.second] = '*';
        }

        for (auto row:field)
        {
            for (auto col:row)
                cout << col;
            cout << "\n";
        }
    }
}
