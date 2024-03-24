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

const ll MOD = 998244353, INF = 1e15;
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
        ll n, k, a;
        cin >> n >> k;

        map<ll, ll> cnt;
        vector<ll> arr;

        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
        }

        for (auto i:cnt) {
            if (i.se >= k)
                arr.push_back(i.fi);
        }

        n = arr.size();

        ll max_size = 0, tot_l = -1;
        for (ll l = 0, r = 0; r < n; r++) {
            if (arr[r] - arr[l] == r - l) {
                ll cur_size = r - l + 1;
                if (cur_size > max_size) {
                    max_size = cur_size;
                    tot_l = arr[l];
                }
            }
            else {
                if (max_size == 0) {
                    max_size = 1;
                    tot_l = arr[l];
                }
                l = r;
            }
        }

        if (tot_l == -1)
            cout << "-1\n";
        else cout << tot_l << " " << tot_l + max_size - 1 << "\n";
    }
}
