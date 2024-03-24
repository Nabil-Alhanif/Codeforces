#include <bits/stdc++.h>
typedef int_fast32_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        if (n == 2)
        {
            cout << "-1\n";
            continue;
        }

        /*
         * 1
         * 1
         *
         * 2
         * -1
         *
         *  3
         *  1 6 2
         *  7 3 8
         *  4 9 5
         *
         *  1 6 2 7 3 8 4 9 5
         *  0 1 2 3 4 5 6 7 8
         *
         *  4
         *  1 9 2 10
         *  3 11 4 12
         *  5 13 6 14
         *  7 15 8 16
         *
         *  1  9  2 10 3 11 4 12 5 13 6  14 7  15 8  16
         *  0  1  2 3  4 5  6 7  8 9  10 11 12 13 14 15
         */

        vector<int> matrix(n*n);

        if (n%2) // Ganjil
        {
            for (int i = 0, j = 1; j <= n*n; i+=2, i%=(n*n), j++)
                matrix[i] = j;
        }
        
        else
        {
            for (int i = 0, j = 1; j <= n*n/2; i+=2, i%=(n*n), j++)
                matrix[i] = j;
            for (int i = 1, j = ((n*n)/2)+1; j <= n*n; i+=2, i%=(n*n), j++)
                matrix[i] = j;
        }

        for (int i = 0; i < n*n; i++)
        {
            if (i && !(i%n))
                cout << "\n";
            cout << matrix[i] << " ";
        }
        cout << "\n";
    }
}
