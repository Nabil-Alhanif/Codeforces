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

const ll MOD = 998244353, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> par(n, -1), dp(n);
    map<ll, ll> cp;
    ll en, mx = 0;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (cp.find(arr[i] - 1) == cp.end()) // Artinya nggak ada
            dp[i] = 1;
        else if (dp[i] < dp[cp[arr[i] - 1]] + 1) {
            dp[i] = dp[cp[arr[i] - 1]] + 1;
            par[i] = cp[arr[i] - 1];
        }

        if (dp[i] > mx) {
            mx = dp[i];
            en = i;
        }
        cp[arr[i]] = i;
    }

    vector<ll> ans;
    while (en != -1) {
        ans.push_back(en + 1);
        en = par[en];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
