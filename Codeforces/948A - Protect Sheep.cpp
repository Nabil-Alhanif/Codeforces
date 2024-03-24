#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 60; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1]) + (combinatoric[i-1][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int row, col;
    cin >> row >> col;

    vector<vector<char>> farm(row + 2, vector<char>(col + 2));
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            cin >> farm[i][j];
    }

    bool bisa = 1;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (farm[i][j] == 'W')
            {
                if (farm[i+1][j] == 'S')
                    bisa = 0;
                if (farm[i-1][j] == 'S')
                    bisa = 0;
                if (farm[i][j+1] == 'S')
                    bisa = 0;
                if (farm[i][j-1] == 'S')
                    bisa = 0;

                if (farm[i+1][j] == '.')
                    farm[i+1][j] = 'D';
                if (farm[i-1][j] == '.')
                    farm[i-1][j] = 'D';
                if (farm[i][j+1] == '.')
                    farm[i][j+1] = 'D';
                if (farm[i][j-1] == '.')
                    farm[i][j-1] = 'D';
            }
        }
    }

    if (!bisa)
        return cout << "No\n", 0;
    cout << "Yes\n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            cout << farm[i][j];
        cout << "\n";
    }
}
