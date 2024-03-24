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

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


struct edge
{
    ll child;
    ll a;
    ll b;
};

void dfs(ll idx, ll limit, ll tot_a, ll tot_b, vector<vector<edge>> &adj_list, vector<ll> &dp, vector<ll> &ans)
{
    if (idx >= limit)
        return;

    ll pos = -1;
    for (ll l = 0, r = dp.size() - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
        if (dp[mid] <= tot_a) {
            pos = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    /*
    cout << "DP: \n";
    for (auto i:dp)
        cout << i << " ";
    cout << "\n";
    cout << "idx: " << idx << " tot_a: " << tot_a << " pos: " << pos << "\n";
    */

    ans[idx] = pos + 1;

    for (auto i:adj_list[idx]) {
        dp.push_back(tot_b + i.b);
        dfs(i.child, limit, tot_a + i.a, tot_b + i.b, adj_list, dp, ans);
        dp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, p, a, b;
        cin >> n;

        vector<vector<edge>> adj_list(n);
        for (int i = 1; i < n; i++) {
            cin >> p >> a >> b;
            adj_list[p - 1].push_back({i, a, b});
        }

        vector<ll> ans(n);
        vector<ll> dp;

        dfs(0, n, 0, 0, adj_list, dp, ans);

        for (int i = 1; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
