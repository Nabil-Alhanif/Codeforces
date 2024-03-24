#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
{
    for (auto i:vect) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

inline void sieve(vector<bool> &vect, bool is_one_prime)
{
    vect[0] = 1;
    if (!is_one_prime)
        vect[1] = 1;

    ll lim = vect.size() - 1;
 
    for (ll i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    ll size = vect.size();
    for (ll i = 0; i <= size; i++) {
        if (!vect[i])
            ret.push_back(i);
    }

    return ret;
}


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

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
        return (this->parent[n]);
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, k, u, v, ans = 0, maks = 0, maxEdge, groupSize;
    cin >> n >> m >> k;

    DSU yaDSU(n);

    vector<bool> gov(n);
    for (int i = 0; i < k; i++) {
        cin >> u;
        u--;
        gov[u] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        yaDSU.combine(u, v);
    }

    // Get the group node of the government
    for (int i = 0; i < n; i++) {
        if (gov[i]) {
            gov[i] = 0;
            gov[yaDSU.findSet(i)] = 1;
        }
    }

    /* Let's connect all the nodes in a group first
     *
     * A graph consisting of n nodes have a maximum
     * of (n * (n - 1)) / 2 edges.
     *
     * So if a graph currently has m nodes, we can
     * add a maximum of ((n * (n - 1)) / 2) - m edges.
     */
    auto groups = yaDSU.findGroup();
    for (auto i:groups) {
        groupSize = i.second.size();
        maxEdge = (groupSize * (groupSize - 1)) / 2;

        ans += (maxEdge - yaDSU.getEdgeCount(i.first));

        // If this is government graph, update value of maks
        if (gov[i.first])
            maks = max(maks, groupSize);
    }

    /* Now let's reiterate and connect non government graph
     * to the largest government graph.
     *
     * If n is the number of node in the government graph, 
     * and m is the number of node in the non government graph,
     * then there are n * m edges we can create between them,
     * as each non government node can connect to all node
     * in the government graph.
     */
    for (auto i:groups) {
        if (!gov[i.first]) {
            groupSize = i.second.size();
            ans += (maks * groupSize);
            maks += groupSize;
        }
    }

    cout << ans << "\n";
}
