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

typedef long double ld;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

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

    // Precompute
    vector<ll> dp(2e5 + 1);
    for (int i = 0; i <= 8; i++)
        dp[i] = 2;
    dp[9] = 3;

    for (int i = 10; i <= 2e5; i++)
        dp[i] = dp[i - 9] + dp[i - 10] % MOD;

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll ans = 0;
        while (n) {
            ans += (((m + (n % 10)) < 10) ? 1 : dp[(m + (n % 10) - 10)]);
            ans %= MOD;
            n /= 10;
        }

        cout << ans << "\n";
    }
}
