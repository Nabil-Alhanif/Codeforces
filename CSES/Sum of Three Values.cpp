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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i + 1;
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        ll need = x - arr[i].fi;
        for (int l = 0, r = n - 1; l < r; ) {
            if (((i != l) && (i != r)) && (arr[l].fi + arr[r].fi == need))
                return cout << arr[i].se << " " << arr[l].se << " " << arr[r].se << "\n", 0;
            else if (arr[l].fi + arr[r].fi < need)
                l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE\n";
}
