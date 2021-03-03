#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const inf = 1e15;

vector<int> Centroid(const vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev)
    {
        sz[u] = 1;
        bool isCentroid = true;
        for (auto v:g[u]) if (v!=prev)
        {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v]>n/2) isCentroid = false;
        }
        if (n-sz[u]>n/2) isCentroid = false;
        if (isCentroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adjList(n);
        for (int i=1; i<n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<int> centroid = Centroid(adjList);
        if (centroid.size()==1)
        {
            for (int i=0; i<n; i++)
            {
                if (adjList[i].size())
                {
                    cout << i+1 << " " << adjList[i][0]+1 << "\n";
                    cout << i+1 << " " << adjList[i][0]+1 << "\n";
                    break;
                }
            }
        }
        else
        {
            bool c1 = true;
            for (auto i:adjList[centroid[0]])
            {
                //cout << "CEN0 " << centroid[0] << " : " << i <<"\n";
                if (i!=centroid[1])
                {
                    c1 = false;
                    cout << i+1 << " " << centroid[0]+1 << "\n";
                    cout << i+1 << " " << centroid[1]+1 << "\n";
                    break;
                }
            }
            if (c1)
            {
                for (auto i:adjList[centroid[1]])
                {
                    if (i!=centroid[0])
                    {
                        cout << i+1 << " " << centroid[1]+1 << "\n";
                        cout << i+1 << " " << centroid[0]+1 << "\n";
                        break;
                    }
                }
            }
        }
    }
}