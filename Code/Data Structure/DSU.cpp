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

    inline vector<pair<int, int>> getExtras()
    {
        return extras;
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
