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

const ll MOD = 1e8, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, root;
        cin >> n;

        vector<vector<ll>> adj_list(n);

        vector<ll> parent(n);
        for (int i = 0; i < n; i++) {
            cin >> parent[i];
            parent[i]--;

            if (i == parent[i])
                root = i;
            else adj_list[parent[i]].push_back(i);
        }

        vector<ll> perm(n);
        for (auto &i:perm) {
            cin >> i;
            i--;
        }

        vector<ll> weight(n, -1), total(n);
        weight[root] = 0;

        /*
        for (int i = 0; i < n; i++) {
            cout << "parent: " << i << " : ";
            for (auto j:adj_list[i])
                cout << j << " ";
            cout << "\n";
        }
        */

        bool bisa = (perm[0] == root);
        for (int i = 1; i < n; i++) {
            bisa &= (weight[parent[perm[i]]] != -1);
            total[perm[i]] = total[perm[i - 1]] + 1;
            weight[perm[i]] = max(total[perm[i]] - total[parent[perm[i]]], (ll)1);
        }

        if (!bisa) {
            cout << "-1\n";
            continue;
        }

        for (auto i:weight)
            cout << i << " ";
        cout << "\n";
    }
}
