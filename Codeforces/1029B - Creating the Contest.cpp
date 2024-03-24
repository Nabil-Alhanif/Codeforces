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
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (auto &i:arr)
        cin >> i;

    vector<ll> pref(n);

    ll max_pos = 0;
    for (int i = 0; i < n; i++) {
        ll pos = 0;
        for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (arr[mid] <= arr[i] * 2) {
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        max_pos = max(pos, max_pos);
        pref[i] = max_pos;
    }

    /*
    for (auto i:pref)
        cout << i << " ";
    cout << "\n";
    */

    ll ans = 0;
    for (ll l = 0, r = 0; l < n; l++) {
        r = l;
        do {
            r = pref[r];
            //cout << l << " " << r << " " << pref[r] << "\n";
        }
        while (r != pref[r]);
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
}
