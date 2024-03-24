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

    ll v;
    cin >> v;

    ll len, min_paint = INF;

    vector<ll> paint(9);
    for (int i = 0; i < 9; i++) {
        cin >> paint[i];
        min_paint = min(min_paint, paint[i]);
    }

    len = v / min_paint;
    v -= (len * min_paint);

    //cout << len << " " << type << " " << min_paint << "\n";

    if (len == 0)
        return cout << "-1\n", 0;

    for (int i = 0, j = 8; i < len; i++) {
        while ((paint[j] - min_paint) > v)
            j--;
        cout << j + 1;
        v -= (paint[j] - min_paint);
    }
    cout << "\n";
}
