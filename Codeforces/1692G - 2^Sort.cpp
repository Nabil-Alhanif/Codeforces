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

    int t;
    cin >> t;

    while (t--) {
        int n, k, ans = 0;
        cin >> n >> k;

        vector<int> arr(n);
        for (auto &i:arr)
            cin >> i;

        vector<int> dp;
        dp.push_back(-1);

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] / arr[i + 1] > 1)
                dp.push_back(i);
        }
        dp.push_back(n - 1);

        for (auto i = dp.begin(); i < dp.end() - 1; i++) {
            //cout << (*i) << " " << (*(i + 1)) << " " << k << "\n";
            ans += max(0, (*(i + 1)) - (*i) - k);
        }

        cout << ans << "\n";
    }
}
