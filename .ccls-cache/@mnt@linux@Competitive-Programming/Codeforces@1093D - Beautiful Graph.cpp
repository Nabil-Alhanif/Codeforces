#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const inf = 1e15, MOD = 998244353;

ll fastExp(ll n)
{
    if (n==0)
        return 1;
    if (n==1)
        return 2;
    ll ret = fastExp(n/2);
    if (n%2)
        return (ret*ret*2)%MOD;
    else return (ret*ret)%MOD;
}

class DSU
{
private:
    int dsuSize;
    vector<vector<int>>child;
    vector<vector<int>>adjList;
    vector<int>parent;
    vector<int>owner;
    vector<int>pos;

public:
    DSU(int n)
    {
        dsuSize = n;
        child.resize(n);
        parent.resize(n);
        adjList.resize(n);
        pos.resize(n);
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

    inline void getOwner()
    {
        for (int i=0; i<dsuSize; i++)
            if (parent[i]==i)
                owner.push_back(i);
    }

    inline void solve()
    {
        ll total = 1;
        for (auto i:owner)
        {
            int locSize = child[i].size()+1;
            vector<vector<int>> urut(locSize);
            stack<pair<int, int>>s;
            pos[i] = 1;
            urut[1].push_back(i);
            for (auto j:adjList[i])
            {
                s.push({j, 2});
                pos[j] = 2;
                urut[2].push_back(j);
            }
            while (!s.empty())
            {
                auto cur = s.top();
                s.pop();
                for (auto j: adjList[cur.first])
                {
                    if (pos[j]==0)
                    {
                        s.push({j, cur.second+1});
                        pos[j] = cur.second+1;
                        urut[cur.second+1].push_back(j);
                    }
                    else
                    {
                        int dif = abs(pos[j]-pos[cur.first]);
                        if (!(dif%2))
                        {
                            cout << "0\n";
                            return;
                        }
                    }
                }
            }
            ll tot1 = 1, tot2 = 1;
            for (int j=1; j<locSize; j++)
            {
                /*cout << "URUT: " << j << "\n";
                for (auto k:urut[j])
                    cout << k << "\n";*/
                if (urut[j].size())
                {
                    if (j%2)
                    {
                        tot1 *= fastExp(urut[j].size());
                        tot1 %= MOD;
                    }
                    else
                    {
                        tot2 *= fastExp(urut[j].size());
                        tot2 %= MOD;
                    }
                }
            }
            tot1 += tot2;
            tot1 %= MOD;
            total *= tot1;
            total %= MOD;
        }
        cout << total << "\n";
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //cout << fastExp(6) << "DAS\n";
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        DSU yaDSU(n);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            yaDSU.combine(u, v);
        }
        yaDSU.getOwner();
        yaDSU.solve();
    }
}