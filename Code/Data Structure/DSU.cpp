#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

class DSU
{
private:
    ll dsuSize;
    vector<vector<ll>>child;
    vector<vector<ll>>adjList;
    vector<ll>parent;
    vector<ll>edgeCount;
    vector<pair<ll, ll>> extras; // If the user try to connect already connected nodes, the data will be stored here

public:
    DSU(ll n)
    {
        this->dsuSize = n;
        this->child.resize(n);
        this->parent.resize(n);
        this->edgeCount.resize(n);
        this->adjList.resize(n);

        for (ll i=0; i<n; i++) {
            this->child[i].push_back(i);
            this->parent[i] = i;
        }
    }

    inline ll findSet(ll n)
    {
        if (this->parent[n] == n)
            return n;
        return (this->findSet(this->parent[n]));
    }

    inline ll getEdgeCount(ll n)
    {
        return (this->edgeCount[this->parent[n]]);
    }

    inline vector<pair<ll, vector<ll>>> findGroup()
    {
        vector<pair<ll, vector<ll>>> ret;
        for (ll i = 0; i < dsuSize; i++) {
            if (this->parent[i] == i)
                ret.push_back({i, this->child[i]});
        }

        return ret;
    }

    inline vector<pair<ll, ll>> getExtras()
    {
        return (this->extras);
    }

    inline void combine(ll a, ll b)
    {
        ll ta = a, tb = b;

        this->adjList[a].push_back(b);
        this->adjList[b].push_back(a);
        a = this->findSet(a);
        b = this->findSet(b);

        if (a != b) {
            if (this->child[a].size() < this->child[b].size())
                swap(a, b);

            this->edgeCount[a] += this->edgeCount[b];
            this->edgeCount[a]++;
            this->edgeCount[b] = this->edgeCount[a];

            while (!this->child[b].empty()) { 
                ll cur = this->child[b].back();
                this->child[b].pop_back();
                this->parent[cur] = a;
                this->child[a].push_back(cur);
            }
        }
        else {
            this->extras.push_back({ta, tb});
            this->edgeCount[a]++;
        }
    }
};
