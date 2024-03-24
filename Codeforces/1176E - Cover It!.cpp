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
 */


class dsu
{
    public:
        ll size;
        vector<ll> depth;
        vector<ll> parent;
        vector<vector<ll>> adj_list;

        dsu(ll n)
        {
            this->size = n;
            this->depth.assign(n, INF);
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->adj_list.resize(n);
        }

        ll find(ll n)
        {
            if (this->parent[n] == n)
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        bool combine(ll u, ll v)
        {
            ll pu = find(u), pv = find(v);
            if (pu != pv) {
                this->parent[pu] = pv;
                this->adj_list[u].push_back(v);
                this->adj_list[v].push_back(u);
                return true;
            }
            return false;
        }

        void dfs(ll idx, ll parent, ll cur_depth)
        {
            this->depth[idx] = cur_depth;
            for (auto i:this->adj_list[idx]) {
                if (i != parent)
                    dfs(i, idx, cur_depth + 1);
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m, u, v;
        cin >> n >> m;

        dsu yaDSU(n);
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--, v--;
            yaDSU.combine(u, v);
        }

        if (n == 2) {
            cout << "1\n 1\n";
            continue;
        }

        yaDSU.dfs(0, -1, 0);

        vector<ll> even, odd;
        for (int i = 0; i < n; i++) {
            //cout << "i: " << i << " depth: " << yaDSU.depth[i] << "\n";
            if (yaDSU.depth[i] % 2)
                odd.push_back(i + 1);
            else even.push_back(i + 1);
        }

        vector<ll> ans;
        if (odd.size() <= even.size())
            ans = odd;
        else ans = even;

        cout << ans.size() << "\n";
        for (auto i:ans)
            cout << i << " ";
        cout << "\n";
    }
}
