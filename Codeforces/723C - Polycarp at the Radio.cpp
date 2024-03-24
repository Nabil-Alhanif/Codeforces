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

const ll MOD = 998244353, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    ll max_play = n / m;
    vector<ll> cnt(n + 2);
    vector<ll> need;

    vector<ll> arr(n);
    for (auto &i:arr) {
        cin >> i;
        cnt[min(i, m + 1)]++;
    }

    for (int i = 1; i <= m; i++) {
        while (cnt[i] < max_play) {
            need.push_back(i);
            cnt[i]++;
        }
    }

    /*
    for (auto i:need)
        cout << i << " ";
    cout << "\n";
    */

    ll needed = need.size();

    cnt.assign(n + 2, 0);
    for (int i = 0, j = 0; (i < n) && (j < needed); i++) {
        if ((arr[i] <= m) && (cnt[min(arr[i], m + 1)] < max_play))
            cnt[min(arr[i], m + 1)]++;
        else {
            arr[i] = need[j];
            j++;
        }
    }

    cout << max_play << " " << needed << "\n";
    for (auto i:arr)
        cout << i << " ";
    cout << "\n";
}
