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

    ll t;
    cin >> t;

    while (t--) {
        ll n, k, u, a, b;
        cin >> n >> k;

        map<ll, ll> mins, maks;
        for (int i = 0; i < n; i++) {
            cin >> u;
            if (mins.find(u) == mins.end())
                mins[u] = i;
            maks[u] = i;
        }

        while (k--) {
            cin >> a >> b;
            if (mins.find(a) == mins.end())
                cout << "NO\n";
            else if (maks.find(b) == maks.end())
                cout << "NO\n";
            else if (mins[a] > maks[b])
                cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
