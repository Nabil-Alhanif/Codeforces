#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const inf = 1e15, MOD = 1e9+7;

vector<vector<ll>>tree;

pair<ll, bool> dfs(ll node, ll par, ll enemy = -1)
{
    //cout << node << " " << par << " " << enemy << "\n";
    bool bisa = !(node==enemy);
    ll child = 1;
    for (auto i:tree[node]) if (i!=par)
    {
        if (!bisa)
            break;
        auto hasil = dfs(i, node, enemy);
        bisa &= hasil.second;
        child += hasil.first;
    }
    if (!bisa) child = 0;
    return {child, bisa};
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    tree.resize(n);
    x--;y--;
    for (ll i=1; i<n; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    //cout << "FLOWER:\n";
    ll flower = 1;
    for (auto i:tree[x])
        flower += dfs(i, x, y).first;
    //cout << "BEE:\n";
    ll bee = 1;
    for (auto i:tree[y])
        bee += dfs(i, y, x).first;
    ll total = (n-1)*n;
    total -= bee*flower;
    cout << total << "\n";
}