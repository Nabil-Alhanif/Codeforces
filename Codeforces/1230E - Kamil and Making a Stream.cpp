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

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


ll get_gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(a, b);
}

ll dfs(ll idx, ll parent, map<ll, ll> _gcd, vector<ll> &beauty, vector<vector<ll>> &adj_list)
{
    ll ret = 0;
    _gcd[beauty[idx]]++;

    map<ll, ll> cpy;
    for (auto &i:_gcd) {
        ll tmp = get_gcd(i.fi, beauty[idx]);
        cpy[tmp] += i.se;
        ret += (i.se * tmp) % MOD;
        ret %= MOD;
    }

    for (auto i:adj_list[idx]) {
        if (i != parent) {
            ret += dfs(i, idx, cpy, beauty, adj_list);
            ret %= MOD;
        }
    }

    return (ret % MOD);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, u, v;
    cin >> n;

    vector<ll> beauty(n);
    for (int i = 0; i < n; i++)
        cin >> beauty[i];

    vector<vector<ll>> adj_list(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    ll ans = dfs(0, -1, *(new map<ll, ll>), beauty, adj_list);
    cout << ans << "\n";
}
