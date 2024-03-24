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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> res;
    res.push_back(0);

    for (ll i = 0, tot = 0; i < n; i++) {
        tot += arr[i];
        if (i + 1 >= m) {
            res.push_back(tot);
            tot -= arr[i - m + 1];
        }
    }

    /*
    for (auto i:res)
        cout << i << " ";
    cout << "\n";
    */

    ll size = res.size();
    vector<vector<ll>> dp(k + 1, vector<ll>(size));

    for (ll type = 1; type < size; type++)
        dp[1][type] = res[type];

    for (ll cnt = 1; cnt <= k; cnt++) {
        for (ll type = 1; type < size; type++) {
            dp[cnt][type] = max(dp[cnt][type], dp[cnt - 1][type]);
            dp[cnt][type] = max(dp[cnt][type], dp[cnt][type - 1]);

            if (type >= m)
                dp[cnt][type] = max(dp[cnt][type], dp[cnt - 1][type - m] + res[type]);
        }
    }

    /*
    for (auto i:dp) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    */

    cout << dp[k][size - 1] << "\n";
}
