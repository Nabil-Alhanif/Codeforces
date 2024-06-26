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

    ll n, a, lim = 2e5 + 1;
    cin >> n;

    set<ll> arr;
    vector<ll> pref(lim);

    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.insert(a);
        pref[a]++;
    }

    for (int i = 1; i < lim; i++)
        pref[i] += pref[i - 1];

    ll ans = 0;
    for (auto i:arr) {
        ll sum = 0;
        for (int j = i; j < lim; j += i)
            sum += (pref[min(j + i - 1, lim - 1)] - pref[j - 1]) * j;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
