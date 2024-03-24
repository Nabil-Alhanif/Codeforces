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

    string s;
    bool flag;

    cin >> s;

    int cnt = 0;
    for (auto i:s)
        cnt = max(cnt, i - '0');

    vector<string> ans(cnt);
    for (int i = 0; i < cnt; i++)
    {
        flag = 0;
        for (auto &j:s)
        {
            if (j != '0')
            {
                ans[i] += '1';
                j--;
                flag = 1;
            }
            else
            {
                if (flag)
                    ans[i] += '0';
            }
        }
    }

    cout << cnt << "\n";
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
