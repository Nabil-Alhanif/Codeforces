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


ll find_depth(ll idx, ll parent, ll cur_depth, vector<ll> &depth, vector<vector<ll>> &adj_list)
{
    //cout << "idx:" << idx << " cur_depth: " << cur_depth << "\n";
    ll other_depth = 0;
    for (auto i:adj_list[idx]) {
        if (i != parent)
            other_depth = max(other_depth, find_depth(i, idx, cur_depth + 1, depth, adj_list));
        //cout << "i: " << i << " other_depth: " << other_depth << "\n";
    }
    depth[idx] = max(cur_depth, other_depth);

    return other_depth + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, u, v;
    cin >> n;

    vector<vector<ll>> adj_list(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    ll root = -1;
    for (int i = 0; i < n; i++) {
        if (adj_list[i].size() <= 1)
            root = i;
    }

    //cout << "root: " << root << "\n";
    vector<ll> depth(n);
    find_depth(root, -1, 0, depth, adj_list);

    /*
    for (int i = 0; i < n; i++)
        cout << "i: " << i << " depth: " << depth[i] << "\n";
    */

    ll q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        ll max_depth = -1;
        root = -1;

        vector<bool> path(n);
        for (int i = 0; i < k; i++) {
            cin >> u;
            u--;

            if (depth[u] > max_depth) {
                max_depth = depth[u];
                root = u;
            }

            path[u] = 1;
        }

        if (root == -1) {
            cout << "NO\n";
            continue;
        }

        ll cnt = 1;

        queue<ll> q;
        vector<bool> vis(n);

        vis[root] = 1;
        q.push(root);

        while (!q.empty()) {
            ll u = q.front();
            //cout << "u: " << u << "\n";
            q.pop();

            for (auto i:adj_list[u]) {
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = 1;

                    // Artinya ini nemu yang kita cari di path
                    if (path[i]) {
                        //cout << "i: " << i << "\n";
                        // Kosongin yang udah ada karena kita nggak perlu nyari sejauh itu lagi
                        // Kita tinggal fokusin jalan di path ini aja
                        while (q.front() != i)
                            q.pop();
                        cnt++;

                        break;
                    }
                }
            }
        }

        /*
        cout << "data: ";
        for (auto i:data)
            cout << i << " ";
        cout << "\n";
        */

        if (cnt == k)
            cout << "YES\n";
        else cout << "NO\n";
    }
}
