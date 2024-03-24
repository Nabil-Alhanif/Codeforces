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

    vector<ll> dp(39);
    dp[0] = 1;
    for (int i = 1; i < 39; i++) {
        dp[i] = dp[i - 1] * 3;
        //cout << dp[i] << " DP\n";
    }

    vector<ll> h1;
    ll lim = pow(2, 20);
    for (int i = 0; i < lim; i++) {
        ll cur = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j))
                cur += dp[j];
        }
        h1.push_back(cur);
    }

    vector<ll> h2;
    lim = pow(2, 19);
    for (int i = 0; i < lim; i++) {
        ll cur = 0;
        for (int j = 0; j < 19; j++) {
            if (i & (1 << (j)))
                cur += dp[20 + j];
        }
        h2.push_back(cur);
    }

    ll pp = h1.size();

    /*
    cout << LLONG_MAX << " LLONG_MAX";
    cout << h2.back() << "\n";
    */

    ll q;
    cin >> q;

    while (q--) {
        ll n, need, ans = LLONG_MAX;
        cin >> n;

        for (auto i:h2) {
            if (i > n)
                ans = min(ans, i);
            else {
                need = n - i;
                if (h1.back() < need)
                    continue;

                ll pos = pp - 1;
                for (ll l = 0, r = pp - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                    if (h1[mid] >= need) {
                        pos = mid;
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }

                ans = min(ans, i + h1[pos]);
            }
        }

        cout << ans << "\n";
    }
}
