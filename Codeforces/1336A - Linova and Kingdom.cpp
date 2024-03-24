#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

typedef int_fast64_t ll;

const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class T>
inline T ceil(T a, T b) // Get ceil of a / b
{
    if (b > 0)
        return ((a + b - 1) / b);
    return 0;
}

template <class T>
inline void printVect2D(vector<vector<T>> &vect)
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

    int_fast32_t lim = vect.size() - 1;
 
    for (int_fast32_t i = 2; i * i <= lim; i++) {
        if (!vect[i]) {
            for (ll j = i * i; j <= lim; j += i)
                vect[j] = 1;
        }
    }
}

inline vector<int> sieve(vector<bool> &vect)
{
    vector<int> ret;

    int_fast32_t size = vect.size();
    for (int_fast32_t i = 0; i <= size; i++) {
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

vector<ll> depth, child, ans;
vector<vector<ll>> adj_list;

ll dfs(ll u, ll v)
{
    child[u] = 1;
    depth[u] = depth[v] + 1;

    for (auto i:adj_list[u]) {
        if (i != v)
            child[u] += dfs(i, u);
    }

    ans[u] = child[u] - depth[u];

    return child[u];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, u, v, ret = 0;
    cin >> n >> k;

    adj_list = vector<vector<ll>>(n + 1);
    depth = vector<ll>(n + 1);
    child = vector<ll>(n + 1);
    ans = vector<ll>(n + 1);

    for (ll i = 1; i < n; i++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 0);
    sort(ans.begin() + 1, ans.end(), greater<ll>());

    /*
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
    */

    for (ll i = 1; i <= n - k; i++)
        ret += ans[i];
    cout << ret << "\n";
}
