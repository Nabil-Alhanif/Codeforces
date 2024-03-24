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


ll func(ll idx, ll limit, ll bad_key, ll good_key_cost, vector<vector<ll>> &bits, vector<vector<ll>> &dp)
{
    if (idx >= limit)
        return 0;

    bad_key = min(bad_key, (ll)62);
    if (dp[idx][bad_key] != -1)
        return dp[idx][bad_key];

    return dp[idx][bad_key] = max(bits[idx][bad_key + 1] + func(idx + 1, limit, bad_key + 1, good_key_cost, bits, dp), bits[idx][bad_key] + func(idx + 1, limit, bad_key, good_key_cost, bits, dp) - good_key_cost);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> bits(n, vector<ll>(64));
        for (auto &i:bits) {
            cin >> i[0];
            for (int j = 1; j < 64; j++)
                i[j] = i[j - 1] / 2;
        }

        vector<vector<ll>> dp(n, vector<ll>(64, -1));
        /*
        vector<vector<ll>> sum(n + 1, vector<ll>(64));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 64; j++)
                sum[i][j] = sum[i + 1][j] + bits[i][j];
        }
        */

        cout << func(0, n, 0, k, bits, dp) << "\n";
    }
}
