#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


bool dfs(ll idx, ll parent, vector<ll> &ans, vector<bool> &type, vector<vector<pair<ll, ll>>> &adj_list)
{
    bool has_been_fixed = 0;
    for (auto i:adj_list[idx]) {
        if (i.fi != parent)
            has_been_fixed |= dfs(i.fi, idx, ans, type, adj_list);
    }

    if (!has_been_fixed && type[idx]) {
        has_been_fixed = 1;
        ans.push_back(idx + 1);
    }

    return has_been_fixed;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, u, v, t;
    cin >> n;

    vector<bool> type(n);
    vector<vector<pair<ll, ll>>> adj_list(n);

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> t;
        u--, v--;

        adj_list[u].push_back({v, t});
        adj_list[v].push_back({u, t});
    }

    queue<pair<ll, ll>> q;
    q.push({0, -1});

    while (!q.empty()) {
        auto [idx, parent] = q.front();
        q.pop();
        for (auto i:adj_list[idx]) {
            if (i.fi != parent) {
                type[i.fi] = (i.se == 2);
                q.push({i.fi, idx});
            }
        }
    }

    /*
    for (auto i:type)
        cout << i << " ";
    cout << "\n";
    */

    vector<ll> ans;

    dfs(0, -1, ans, type, adj_list);

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
