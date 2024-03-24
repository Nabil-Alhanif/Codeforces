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


ll lim = 2e5 + 1;
vector<ll> fact(lim);
vector<ll> inv(lim);

ll kombin(ll n, ll k)
{
    if (k > n)
        return 0;

    if (k == n)
        return 1;

    return (((fact[n] * inv[k]) % MOD) * (inv[n - k] % MOD)) % MOD;
}

ll fastPow(ll n, ll base)
{
    if (n <= 0)
        return 1;
    if (n == 1)
        return base % MOD;

    ll half = fastPow(n / 2, base);
    if (n % 2)
        return ((half * half) % MOD * base) % MOD;
    return (half * half) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Precompute factorials and inverse
    fact[0] = 1;
    inv[0] = 1;
    inv[1] = 1;

    for (ll i = 1; i < lim; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = fastPow(MOD - 2, fact[i]);
    }

    ll t;
    cin >> t;

    while (t--) {
        ll n, m, k, ans = 0;
        cin >> n >> m >> k;
        m--;

        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            ll cnt = 0;
            for (ll l = i, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (arr[mid] <= arr[i] + k) {
                    cnt = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            cnt -= i;

            //cout << i << " " << cnt << " " << m << " " << kombin(cnt, m) << "\n";
            ans += kombin(cnt, m);
            ans %= MOD;
        }

        cout << ans << "\n";
    }
}
