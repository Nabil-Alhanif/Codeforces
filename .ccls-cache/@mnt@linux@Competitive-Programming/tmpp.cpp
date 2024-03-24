#include <algorithm>
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

typedef long double ld;
typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

typedef complex<ll> pt;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class Solve
{
    public:
        ll n;
        vector<vector<ll>> adj_list;
        vector<ll> order;
        vector<ll> parent;
        vector<bool> vis;

        Solve()
        {
            cin >> this->n;

            this->adj_list.resize(n);
            this->parent.resize(n);
            this->vis.resize(n);

            for (int i = 0; i < n; i++)
                this->parent[i] = i;

            ll v;
            for (int i = 0; i < this->n; i++) {
                cin >> v;
                this->adj_list[i].push_back(v);
            }

            for (int i = 0; i < n; i++) {
                if (!this->vis[i]) {
                    this->vis[i] = 1;
                    dfs(i);
                    this->order.push_back(i);
                }
            }

            this->vis.assign(n, 0);
        }

        void dfs(ll cur)
        {
            this->vis[cur] = 1;

            for (auto i:adj_list[cur]) {
                if (!this->vis[i]) {
                    combine(cur, i);
                    this->vis[i] = 1;
                    dfs(i);
                    this->order.push_back(i);
                }
            }
        }

        ll find(ll a)
        {
            if (this->parent[a] == a)
                return a;
            return this->parent[a] = find(this->parent[a]);
        }

        void combine(ll a, ll b)
        {
            ll pa = find(a);
            ll pb = find(b);

            if (pa == pb)
                return;

            this->parent[pa] = pb;
        }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Solve();
}
