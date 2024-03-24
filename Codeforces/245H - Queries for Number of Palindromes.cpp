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

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


ll lim = 5001;
string s;

vector<vector<ll>> dp(lim, vector<ll>(lim));
vector<vector<bool>> vis(lim, vector<bool>(lim));

bool rec(ll l, ll r) {
    if (vis[l][r])
        return (dp[l][r] > 0);
    vis[l][r] = 1;

    if (l > r)
        return 1;

    if (l == r) {
        dp[l][r]++;
        return 1;
    }

    rec(l + 1, r);
    rec(l, r - 1);

    if ((s[l - 1] == s[r - 1]) && rec(l + 1, r - 1)) {
        dp[l][r]++;
        return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    ll size = s.size();
    rec(1, size);

    /*
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    */

    for (int i = 1; i < lim; i++) {
        for (int j = 1; j < lim; j++)
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }

    ll q;
    cin >> q;

    ll l, r;
    while (q--) {
        cin >> l >> r;
        ll ans = dp[r][r] - dp[l - 1][r] - dp[r][l - 1] + dp[l - 1][l - 1];
        cout << ans << "\n";
    }
}
