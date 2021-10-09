#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));

void count_combinatoric()
{
    // Base case
    for (int i = 0; i <= 60; i++)
        combinatoric[i][0] = 1;

    for (int i = 1; i <= 60; i++)
    {
        for (int j = 1; j <= 60; j++)
            combinatoric[i][j] = ((combinatoric[i-1][j-1]) + (combinatoric[i-1][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b, root = 0, cnt = 0;
    cin >> n;

    vector<int> ans;
    vector<vector<int>> adjacency_matrix(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--; b--; // Di min min karena indexing dari 0
        adjacency_matrix[a].push_back(b);
        adjacency_matrix[b].push_back(a);
    }

    /**
     * Cek ada berapa banyak node yang punya lebih dari 2 path
     * Soalnya kalau dia ada lebih dari dua path, dia bakal jadi root dari
     * decomposition nya. Kalau mau tau kenapa dai jadi root, baca soal yang bener -_-
     * Kalau yang punya path ada lebih dari 2, artinya
     * graf ini nggak ada decomposition nya.
     */

     for (int i = 0; i < n; i++)
     {
         if (adjacency_matrix[i].size() > 2)
         {
             root = i;
             cnt++;
         }
     }

     if (cnt > 1)
         return cout << "No\n", 0;

     // Abis tu bfs buat cari ujung ujung dari graf nya
     queue<pair<int, int>> bfs; // Node sekarang dan node parent nya
     bfs.push({root, -1});
     while (!bfs.empty())
     {
         int cur_node = bfs.front().first;
         int par_node = bfs.front().second;
         int degree = 0;
         bfs.pop();

         // Kalau bukan paling ujung kita iterasi
         for (auto next_node:adjacency_matrix[cur_node])
         {
             if (next_node != par_node)
             {
                 bfs.push({next_node, cur_node});
                 degree++;
             }
         }

         if (degree == 0) // Artinya dia udah paling ujung
             ans.push_back(cur_node);
     }

     cout << "Yes\n";
     cout << ans.size() << "\n";
     for (auto i:ans)
         cout << root + 1 << " " << i + 1 << "\n";
}
