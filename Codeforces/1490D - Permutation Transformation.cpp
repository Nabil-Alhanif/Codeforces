#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
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

    int t, n, l, r, pos, maks, cur_dist;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> ar(n), depth(n);
        for (auto &i:ar)
        {
            cin >> i;
            i--;
        }

        queue<pair<pair<int, int>, int>> bfs;
        bfs.push({{0, n - 1}, 0});

        while (!bfs.empty())
        {
            l = bfs.front().first.first;
            r = bfs.front().first.second;
            cur_dist = bfs.front().second;
            bfs.pop();

            maks = -MOD;
            for (int i = l; i <= r; i++)
            {
                if (ar[i] >= maks)
                {
                    maks = ar[i];
                    pos = i;
                }
            }

            depth[pos] = cur_dist;

            if (l <= pos - 1)
                bfs.push({{l, pos - 1}, cur_dist + 1});
            if (pos + 1 <= r)
                bfs.push({{pos + 1, r}, cur_dist + 1});
        }

        for (auto i:depth)
            cout << i << " ";
        cout << "\n";
    }
}
