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

    bool flag = 1;
    int n, u, cnt, cur_node, parent;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++)
    {
        cin >> u;
        graph[u - 1].push_back(i);
        graph[i].push_back(u - 1);
    }

    queue<pair<int, int>> q;
    q.push({0, -1});

    while (!q.empty())
    {
        cnt = 0;

        cur_node = q.front().first;
        parent = q.front().second;
        //cout << cur_node << " " << parent << "\n";
        q.pop();

        for (auto i:graph[cur_node])
        {
            if (graph[i].size() == 1)
                cnt++;

            else if (i != parent)
                q.push({i, cur_node});
        }

        flag &= (cnt >= 3);
    }

    cout << (flag ? "Yes\n" : "No\n");
}
