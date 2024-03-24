#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q, k;
    cin >> n >> q >> k;

    vector<ll> arr(n);
    for (auto &i:arr)
        cin >> i;

    vector<ll> dp(n);

    if (n >= 2)
        dp[0] = arr[1] - 2;
    else dp[0] = k - 1;

    for (int i = 1; i < n - 1; i++) {
        dp[i] = arr[i + 1] - arr[i - 1] - 2;
        dp[i] += dp[i - 1];
    }
    if (n >= 2)
        dp[n - 1] = dp[n - 2] + k - arr[n - 2] - 1;

    /*
    for (auto i:dp)
        cout << i << " ";
    cout << "\n";
    */

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        ll ans = 0;

        if (l == r)
            ans = k - 1;
        else {
            ans = dp[r - 1] - dp[l];
            ans += arr[l + 1] - 2;
            ans += k - arr[r - 1] - 1;
        }

        cout << ans << "\n";
    }
}
