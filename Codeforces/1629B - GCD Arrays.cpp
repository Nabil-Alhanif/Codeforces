#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19
 
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;
 
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
 

/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;

        if (l == r) {
            if (l == 1)
                cout << "NO\n";
            else cout << "YES\n";
            continue;
        }

        ll ans = (r - l + 1) / 2;
        if ((l % 2) && (r % 2))
            ans++;

        if (k >= ans)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
