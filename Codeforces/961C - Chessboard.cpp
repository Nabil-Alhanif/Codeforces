#include <bits/stdc++.h>
using namespace std;
typedef uint_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

struct board
{
    vector<string> piece;
    int change_odd;
    int change_even;

    board(int n)
    {
        this->piece.resize(n);
        this->change_even = 0;
        this->change_odd = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<board> pieces(4, board(n));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> pieces[i].piece[j];

        //cout << "AWAL " << pieces[i].change_odd << " " << pieces[i].change_even << "\n";

        // Anggap dia kiri atas
        //cout << "KASUS 1\n";
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                //cout << pieces[i].piece[row][col];
                if ((row % 2) == (col % 2))
                {
                    if (pieces[i].piece[row][col] != '1')
                        pieces[i].change_odd++;
                    //cout << " " << row << " " << col << " SAMA\n";
                }
                else
                {
                    if (pieces[i].piece[row][col] != '0')
                        pieces[i].change_odd++;
                    //cout << " " << row << " " << col << " BEDA\n";
                }
            }
            //cout << "\n";
        }

        // Anggap dia kanan atas
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if ((row % 2) == (col % 2))
                {
                    if (pieces[i].piece[row][col] != '0')
                        pieces[i].change_even++;
                }
                else
                {
                    if (pieces[i].piece[row][col] != '1')
                        pieces[i].change_even++;
                }
            }
        }

        // DEBUG
        /*
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
                cout << pieces[i].piece[row][col];
            cout << "\n";
        }
        cout << pieces[i].change_odd << " " << pieces[i].change_even << "\n\n";
        */
    }

    ll ans = INF;

    for (int satu = 1; satu <= 4; satu++)
    {
        for (int dua = 1; dua <= 4; dua++)
        {
            for (int tiga = 1; tiga <= 4; tiga++)
            {
                for (int empat = 1; empat <= 4; empat++)
                {
                    if ((satu != dua) && ((satu != tiga) && (satu != empat)))
                    {
                        if ((dua != tiga) && (dua != empat))
                        {
                            if (tiga != empat)
                            {
                                // Artinya semuanya udah pasti beda ya
                                ll tmp = 0;

                                if (satu % 2) // Kiri atas
                                    tmp += pieces[0].change_odd;
                                else tmp += pieces[0].change_even;

                                if (dua % 2) // Kiri atas
                                    tmp += pieces[1].change_odd;
                                else tmp += pieces[1].change_even;

                                if (tiga % 2)
                                    tmp += pieces[2].change_odd;
                                else tmp += pieces[2].change_even;

                                if (empat % 2)
                                    tmp += pieces[3].change_odd;
                                else tmp += pieces[3].change_even;

                                ans = min(ans, tmp);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}
