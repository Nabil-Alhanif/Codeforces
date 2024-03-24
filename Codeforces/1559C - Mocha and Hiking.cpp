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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> s(n);
        for (auto &i:s)
            cin >> i;

        if (s[n - 1] == 0) {
            for (int i = 0; i <= n; i++)
                cout << i + 1 << " ";
            cout << "\n";
            continue;
        }
        else if (s[0] == 1) {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++)
                cout  << i << " ";
            cout << "\n";
            continue;
        }

        bool ada = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] == 0) && (s[i + 1] == 1)) {
                for (int j = 1; j <= i + 1; j++)
                    cout << j << " ";
                cout << n + 1 << " ";
                for (int j = i + 2; j <= n; j++)
                    cout << j << " ";
                cout << "\n";

                ada = 1;
                break;
            }
        }

        if (!ada)
            cout << "-1\n";
    }
}
