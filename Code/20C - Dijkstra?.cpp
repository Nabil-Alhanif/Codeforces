#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, a, b, w;
    cin >> n >> m;
    
    vector<vector<pair<ll,ll>>> adjacency_matrix(n+1); // Node, Weight
    vector<ll> distance(n+1);
    vector<ll> closest_neighbor(n+1, -1);
    vector<ll> ans;

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> dijkstra; // {Distance from source, {next point, current point}} PLEASE DON'T GET CONFUSED WITH THIS FFS

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adjacency_matrix[a].push_back({b, w});
        adjacency_matrix[b].push_back({a, w});
    }

    /*
    for (auto &node:adjacency_matrix)
    {
        cout << (&node - &adjacency_matrix[0]) << " : ";
        for (auto con:node)
            cout << "{ " << con.first << " . " << con.second << " } <- ";
        cout << "End\n";
    }
    */

    dijkstra.push({0, {1, 0}});
    
    while (!dijkstra.empty())
    {
        pair<ll, pair<ll, ll>> cur_data = dijkstra.top();
        dijkstra.pop();
        ll cur_dist = cur_data.first; // Current node distance from source
        ll cur_node = cur_data.second.first; // Current node
        ll last_node = cur_data.second.second; // Last node

        if (closest_neighbor[cur_node] != -1) // Artinya udah dikunjungin
            continue;

        distance[cur_node] = cur_dist;
        closest_neighbor[cur_node] = last_node;

        for (auto &con:adjacency_matrix[cur_node])
        {
            if (closest_neighbor[con.first] == -1)
                dijkstra.push({cur_dist + con.second, {con.first, cur_node}});
        }
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << distance[i] << " " << closest_neighbor[i] << "\n";
    }
    */

    if (closest_neighbor[n] == -1) // Artinya nggak kehubung
    {
        cout << "-1\n";
        return 0;
    }

    int cur_node = n;
    while (cur_node != 1)
    {
        ans.push_back(cur_node);
        cur_node = closest_neighbor[cur_node];
    }

    cout << 1;
    int size = ans.size();
    for (int i = size - 1; i >= 0; i--)
        cout << " " << ans[i];
    cout << "\n";
}
