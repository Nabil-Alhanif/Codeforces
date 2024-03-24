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

const ll MOD = 1e8, INF = 4e18;
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
        ll n, u, v;
        cin >> n;

        bool bisa = 1;

        vector<pair<ll, ll>> arr;
        map<pair<ll, ll>, ll> ans;

        vector<vector<ll>> adj_list(n);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            u--, v--;

            if (v < u)
                swap(u, v);
            arr.push_back({u, v});

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            bisa &= (adj_list[u].size() <= 2);
            bisa &= (adj_list[v].size() <= 2);
        }

        if (!bisa) {
            cout << "-1\n";
            continue;
        }

        ll root = 0, parent = -1;
        for (int i = 0; i < n; i++) {
            if (adj_list[i].size() == 1) {
                root = i;
                break;
            }
        }

        bool type = 0;
        ll cnt = 1;

        while (1) {
            if ((root != -1) && (parent != -1)) {
                ans[{min(root, parent), max(root, parent)}] = (type ? 2 : 3);
                type ^= 1;
            }

            bool changed = 0;
            for (auto i:adj_list[root]) {
                if (i != parent) {
                    changed = 1;
                    parent = root;
                    root = i;
                    break;
                }
            }

            if (!changed)
                break;
        }

        for (auto i:arr)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
