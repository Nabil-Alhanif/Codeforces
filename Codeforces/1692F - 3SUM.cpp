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
        int n, a;
        cin >> n;

        vector<int> cnt(10);
        while (n--) {
            cin >> a;
            a %= 10;
            cnt[a]++;
        }

        vector<int> arr;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < min(3, cnt[i]); j++)
                arr.push_back(i);
        }

        bool ada = 0;

        for (auto i = arr.begin(); i < arr.end() && !ada; i++) {
            for (auto j = i + 1; j < arr.end() && !ada; j++) {
                for (auto k = j + 1; k < arr.end() && !ada; k++) {
                    a = (*i) + (*j) + (*k);
                    a %= 10;
                    ada |= (a == 3);
                }
            }
        }

        cout << (ada ? "YES\n" : "NO\n");
    }
}