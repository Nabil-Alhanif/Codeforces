#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ios>

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


ll fastExp(ll base, ll pow) {
    ll ret = 1;
    while (pow > 0) {
        if (pow & 1)
            ret *= base;
        pow >>= 1;
        base *= base;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, x;
    cin >> n >> k >> x;

    ll upd = fastExp(x, k);

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> pref(n + 1);
    pref.push_back(0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] | arr[i];

    vector<ll> suff(n + 1);
    suff.push_back(0);
    for (int i = n; i > 0; i--)
        suff[i] = suff[i + 1] | arr[i - 1];

    /*
    for (int i = 1; i <= n; i++)
        cout << pref[i] << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++)
        cout << suff[i] << " ";
    cout << "\n";
    */

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << pref[i - 1] << " " << suff[i + 1] << " " << (arr[i - 1] * upd) << "\n";
        ans = max(ans, (pref[i - 1] | suff[i + 1] | (arr[i - 1] * upd)));
    }
    cout << ans << "\n";
}
