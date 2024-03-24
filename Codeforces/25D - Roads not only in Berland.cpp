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

    int n, u, v;
    cin >> n;

    DSU yaDSU(n);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        u--;v--;
        yaDSU.combine(u, v);
    }

    vector<pair<int, vector<int>>> groups = yaDSU.findGroup();
    /*
    for (auto i:groups)
    {
        cout << "\n" << i.first << ":\n";
        for (auto j:i.second)
            cout << j << " ";
        cout << "\n";
    }
    */

    int size = groups.size();
    cout << size - 1 << "\n";
    for (int i = 0; i < size - 1; i++)
        cout << yaDSU.extras[i].first + 1 << " " << yaDSU.extras[i].second + 1 << " " << groups[i].first + 1 << " " << groups[i + 1].first + 1 << "\n";
}
