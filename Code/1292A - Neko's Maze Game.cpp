#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, q, r, c, cnt = 0, change;
    cin >> n >> q;

    vector<vector<bool>> maze(2, vector<bool>(n));
    while (q--)
    {
        cin >> r >> c;
        r--;c--;

        if (maze[r][c])
            change = -1;
        else change = 1;

        maze[r][c] = maze[r][c] ^ 1;

        for (int i = -1; i <= 1; i++)
        {
            if ((c + i < 0) || (c + i >= n))
                continue;

            if (maze[1 - r][c + i])
                cnt += change;
        }

        cout << ((cnt == 0) ? "Yes\n" : "No\n");
    }
}
