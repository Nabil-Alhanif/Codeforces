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

const ll MOD = 1e8, INF = 4e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


struct vertex
{
    ll l;
    ll r;
};

ll dfs(ll idx, ll parent, ll type, vector<vertex> &arr, vector<vector<ll>> &adj_list, vector<vector<ll>> &dp)
{
    if (dp[idx][type] != -1)
        return dp[idx][type];

    ll ret = 0;
    ll cur_val = (type == 0 ? arr[idx].l : arr[idx].r);
    for (auto i:adj_list[idx]) {
        if (i != parent) {
            ll kiri, kanan;

            // Itung kalau kita ambil yang kiri
            kiri = dfs(i, idx, 0, arr, adj_list, dp) + abs(cur_val - arr[i].l);

            // Itung kalau ambil kanan
            kanan = dfs(i, idx, 1, arr, adj_list, dp) + abs(cur_val - arr[i].r);

            ret += max(kiri, kanan);
        }
    }

    return dp[idx][type] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, u, v;
        cin >> n;

        vector<vertex> arr(n);
        for (auto &i:arr)
            cin >> i.l >> i.r;

        vector<vector<ll>> adj_list(n);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            u--, v--;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        ll kiri = dfs(0, -1, 0, arr, adj_list, dp);
        ll kanan = dfs(0, -1, 1, arr, adj_list, dp);

        ll ans = max(kiri, kanan);
        cout << ans << "\n";
    }
}
