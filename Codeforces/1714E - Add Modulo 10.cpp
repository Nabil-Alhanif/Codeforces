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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> lima, sepuluh;

        vector<ll> arr(n);
        for (auto &i:arr) {
            cin >> i;
            if (i % 10 == 0)
                sepuluh.push_back(i);
            else if (i % 5 == 0)
                lima.push_back(i);
        }

        sort(sepuluh.begin(), sepuluh.end());
        sort(lima.begin(), lima.end());

        ll cnt_sepuluh, cnt_lima;
        cnt_sepuluh = unique(sepuluh.begin(), sepuluh.end()) - sepuluh.begin();
        cnt_lima = unique(lima.begin(), lima.end()) - lima.begin();

        if (cnt_sepuluh || cnt_lima) {
            if (((cnt_sepuluh == 1) && (cnt_lima == 1)) && (n == (sepuluh.size() + lima.size()))) {
                if (lima[0] + 5 == sepuluh[0])
                    cout << "Yes\n";
                else cout << "No\n";
            }
            else if ((cnt_sepuluh == 1) && (n == sepuluh.size()))
                cout << "Yes\n";
            else if ((cnt_lima == 1) && (n == lima.size()))
                cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        for (auto &i:arr) {
            i %= 20;
            while (i % 10 != 2) {
                //cout << i << "\n";
                i += (i % 10);
            }
            i %= 20;
        }

        sort(arr.begin(), arr.end());
        ll cnt = unique(arr.begin(), arr.end()) - arr.begin();

        if (cnt == 1)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
