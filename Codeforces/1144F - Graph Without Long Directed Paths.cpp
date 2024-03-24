#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;
typedef __uint128_t u128;
typedef __int128_t i128;

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

public: // Bad practice? IDC
    vector<pair<int, int>> extras; // If the user try to connect already connected nodes, the data will be stored here

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
        int ta = a, tb = b;

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
        else extras.push_back({ta, tb});
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

    ll n, m, u, v, cur_node, parent, cur_color;
    bool flag = 1;

    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<pair<int, int>> edges;
    vector<int> color(n, -1);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--,v--;
        edges.push_back({u, v});
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({{0, -1}, 0});

    while ((!q.empty()) && flag)
    {
        cur_node = q.front().first.first;
        parent = q.front().first.second;
        cur_color = q.front().second;
        q.pop();

        color[cur_node] = cur_color;
        for (auto i:graph[cur_node])
        {
            if (i != parent)
            {
                if (color[i] == cur_color)
                {
                    flag = 0;
                    break;
                }

                if (color[i] == -1)
                    q.push({{i, cur_node}, cur_color ^ 1});
            }
        }
    }

    if (flag)
    {
        cout << "YES\n";

        for (auto i:edges)
            cout << color[i.second];

        cout << "\n";
    }
    else cout << "NO\n";
}
