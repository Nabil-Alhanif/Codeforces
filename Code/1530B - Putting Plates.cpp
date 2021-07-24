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
        int h, w;
        cin >> h >> w;

        vector<vector<int>> table(h, vector<int>(w));
        table[0][0] = 1;
        table[0][w-1] = 1;
        table[h-1][0] = 1;
        table[h-1][w-1] = 1;

        for (int i = 2; i < h-2; i += 2)
        {
            table[i][0] = 1;
            table[i][w-1] = 1;
        }

        for (int i = 2; i < w-2; i += 2)
        {
            table[0][i] = 1;
            table[h-1][i] = 1;
        }

        for (auto i:table)
        {
            for (auto j:i)
                cout << j;
            cout << "\n";
        }
    }
}
