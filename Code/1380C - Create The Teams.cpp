#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

class DSU
{
private:
    int dsuSize;
    vector<vector<int>>child;
    vector<vector<int>>adjList;
    vector<int>parent;
    vector<int>color;

public:
    DSU(int n)
    {
        dsuSize = n;
        child.resize(n);
        parent.resize(n);
        color.resize(n);
        adjList.resize(n);
        for (int i=0; i<n; i++)
        {
            child[i].push_back(i);
            parent[i] = i;
        }
    }

    inline int findSet(int n)
    {
        return parent[n];
    }

    inline vector<pair<int, vector<int>>> findGroup()
    {
        vector<pair<int, vector<int>>> ret;
        for (int i = 0; i < dsuSize; i++)
        {
            if (parent[i] == i)
                ret.push_back({i, child[i]});
        }

        return ret;
    }

    inline void combine(int a, int b)
    {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        a = findSet(a);
        b = findSet(b);

        if (a!=b)
        {
            if (child[a].size()<child[b].size())
                swap(a, b);
            while (!child[b].empty())
            {
                int cur = child[b].back();
                child[b].pop_back();
                parent[cur] = a;
                child[a].push_back(cur);
            }
        }
    }
};

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

    ll t, n, x, team;
    cin >> t;

    while (t--)
    {
        cin >> n >> x;

        vector<ll> skill(n), dp(n + 1);
        for (auto &i:skill)
            cin >> i;
        sort(skill.begin(), skill.end());

        dp[n] = 0;

        for (int i = n - 1; i >= 0 ; i--)
        {
            team = (x + skill[i] - 1) / skill[i];

            //cout << i << " " << x << " " << skill[i] << " " << team << " ixst\n";
            if (i + team - 1 >=n)
            {
                dp[i] = dp[i + 1];
                continue;
            }

            if (i != n - 1)
                dp[i]  = dp[i + 1];

            dp[i] = max(dp[i], dp[i + team] + 1);

            //cout << dp[i] << " " << i << " " << skill[i] << " " << team << "\n";
        }

        cout << dp[0] << "\n";
    }
}
