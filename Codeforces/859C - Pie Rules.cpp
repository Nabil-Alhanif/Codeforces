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


ll n;
vector<ll> pies;
vector<ll> suff;

vector<ll> alice_dp;
vector<ll> bob_dp;

ll bob(ll idx);
ll alice(ll idx);

ll bob(ll idx)
{
    if (idx >= n)
        return 0;

    if (bob_dp[idx] != -1)
        return bob_dp[idx];

    return bob_dp[idx] = max(pies[idx] + suff[idx + 1] - alice(idx + 1), bob(idx + 1));
}

ll alice(ll idx)
{
    if (idx >= n)
        return 0;

    if (alice_dp[idx] != -1)
        return alice_dp[idx];

    return alice_dp[idx] = max(pies[idx] + suff[idx + 1] - bob(idx + 1), alice(idx + 1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    pies.resize(n);
    for (auto &i:pies)
        cin >> i;

    suff.resize(n + 1);
    suff[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suff[i] = suff[i + 1] + pies[i];

    alice_dp.assign(n, -1);
    bob_dp.assign(n, -1);

    ll bob_tot = bob(0);
    ll alice_tot = suff[0] - bob_tot;

    cout << alice_tot << " " << bob_tot << "\n";
}
