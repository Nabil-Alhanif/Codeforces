#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

vector<vector<ll>> combinatoric(61, vector<ll>(61));
vector<vector<ll>> tree;
vector<int> color;

ll ans = 0, red = 0, blue = 0;

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

pair<ll, ll> dfs(int cur_node, int par_node)
{
    pair<ll, ll> ret; // Red, blue
    if (color[cur_node] == 1)
        ret.first++;
    else if (color[cur_node] == 2)
        ret.second++;

    for (auto i:tree[cur_node])
    {
        if (i != par_node)
        {
            pair<int, int> tot_col = dfs(i, cur_node); // Warna merah dan biru kalau jalan ke arah i

            //cout << i << " " << cur_node << " " << tot_col.first << " " << tot_col.second << "\n";
            if ((tot_col.first == red) && (tot_col.second == 0)) // Artinya semua warna merah ada di arah i dan nggak ada warna biru
                ans++;
            else if ((tot_col.first == 0) && (tot_col.second == blue)) // Semua warna biru di arah i dan nggak ada warna merah
                ans++;

            // Hasil dari dfs nya tambahin ke data kita sekarang
            ret.first += tot_col.first;
            ret.second += tot_col.second;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, v, u;
    cin >> n;

    tree.resize(n);
    color.resize(n);
    for (auto &i:color)
    {
        cin >> i;
        if (i == 1)
            red++;
        else if (i == 2)
            blue++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> v >> u;
        v--; u--; // Biar indexing dari 1
        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    ///dfs(0, -1);
    /* GAGAL
    queue<pair<pair<int, int>, pair<int,int>>> q; // {{cur, par}, {red, blue}}
    q.push({{0, -1}, {0, 0}});
    while (!q.empty())
    {
        ll cur_node = q.front().first.first;
        ll par_node = q.front().first.second;

        ll cur_red = q.front().second.first;
        ll cur_blue = q.front().second.second;
        q.pop();

        cout << cur_node << " " << par_node << " " << cur_red << " " << cur_blue << "\n";

        if ((cur_red == red) && (cur_blue == 0)) // Artinya semua warna merah ada di sisi parent
            ans++;
        else if ((cur_red == 0) && (cur_blue == blue)) // Artinya semua warna biru ada di sisi parent
            ans++;
        // DI ans++ karena artinya kita bisa potong jalan antara cur_node dan par_node;

        if (color[cur_node] == 1)
            cur_red++;
        else if (color[cur_node] == 2)
            cur_blue++;

        for (auto i:tree[cur_node])
        {
            if (i != par_node)
                q.push({{i, cur_node}, {cur_red, cur_blue}});
        }
    }
    */

    dfs(0, -1);
    cout << ans << "\n";
}

