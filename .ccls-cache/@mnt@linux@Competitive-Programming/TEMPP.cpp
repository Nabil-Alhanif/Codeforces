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

template <typename T>
using pt = complex<T>;
#define X real()
#define Y imag()

const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class Graph
{
    public:
        ll size;
        ll time;
        vector<ll> depth;
        vector<ll> parent;
        vector<vector<ll>> adj_list;
        vector<vector<ll>> jump;
        vector<pair<ll, ll>> timer;

        Graph(ll n)
        {
            this->size = n;
            this->depth.resize(n);
            this->parent.resize(n);
            this->adj_list.resize(n);
            this->jump.assign(n, vector<ll>(32));
            this->timer.resize(n);
        }

        void dfs(ll cur, ll par, ll dep)
        {
            this->timer[cur].fi = time++;
            this->depth[cur] = dep;

            this->jump[cur][0] = this->parent[cur];
            for (int i = 1; i < 32; i++)
                this->jump[cur][i] = this->jump[this->jump[cur][i - 1]][i - 1];

            for (auto i:this->adj_list[cur]) {
                if (i == par)
                    continue;

                this->parent[i] = cur;
                dfs(i, cur, dep + 1);
            }

            this->timer[cur].se = time++;
        }

        bool check(ll u, ll v)
        {
            return ((this->timer[u].fi <= this->timer[v].fi) && (this->timer[u].se >= this->timer[v].se));
        }

        ll lca(ll u, ll v) {
            if (check(u, v))
                return u;
            if (check(v, u))
                return v;

            if (this->depth[u] > this->depth[v])
                swap(u, v);

            for (ll st = 31; st >= 0; st--) {
                if (!check(this->jump[u][st], v))
                    u = this->jump[u][st];
            }
            return this->jump[u][0];
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q;
    cin >> n >> q;

    Graph graph(n);
    for (int i = 1; i < n; i++) {
        ll v;
        cin >> v;
        v--;
        graph.adj_list[i].push_back(v);
        graph.adj_list[v].push_back(i);
    }

    graph.dfs(0, -1, 0);

    while (q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;

        if (a == b) {
            ll meet = graph.lca(a, c);
            ll d1 = abs(graph.depth[a] - graph.depth[meet]) + 1;
            ll d2 = abs(graph.depth[c] - graph.depth[meet]) + 1;
            cout << d1 + d2 - 1 << "\n";
            continue;
        }
        else if (a == c) {
            ll meet = graph.lca(a, b);
            ll d1 = abs(graph.depth[a] - graph.depth[meet]) + 1;
            ll d2 = abs(graph.depth[b] - graph.depth[meet]) + 1;
            cout << d1 + d2 - 1 << "\n";
            continue;
        }
        else if (b == c) {
            ll meet = graph.lca(b, a);
            ll d1 = abs(graph.depth[a] - graph.depth[meet]) + 1;
            ll d2 = abs(graph.depth[b] - graph.depth[meet]) + 1;
            cout << d1 + d2 - 1 << "\n";
            continue;
        }

        ll ans = 0;

        ll meet, lc_m, dis_tar, dis_mee;
        // Cek kalau A jadi target
        meet = graph.lca(b, c);
        lc_m = graph.lca(a, meet);
        dis_tar = abs(graph.depth[a] - graph.depth[lc_m]);
        dis_mee = abs(graph.depth[meet] - graph.depth[lc_m]);
        ans = max(ans, dis_tar + dis_mee + 1);

        cout << a << " " << meet << " " << lc_m << " " << graph.depth[a] << " " << graph.depth[meet] << " " << graph.depth[lc_m] << " " << dis_tar << " " << dis_mee << "\n";

        // Cek kalau B jadi target
        meet = graph.lca(a, c);
        lc_m = graph.lca(b, meet);
        dis_tar = abs(graph.depth[b] - graph.depth[lc_m]);
        dis_mee = abs(graph.depth[meet] - graph.depth[lc_m]);
        ans = max(ans, dis_tar + dis_mee + 1);

        cout << b << " " << meet << " " << lc_m << " " << graph.depth[b] << " " << graph.depth[meet] << " " << graph.depth[lc_m] << " " << dis_tar << " " << dis_mee << "\n";

        // Cek kalau C jadi target
        meet = graph.lca(a, b);
        lc_m = graph.lca(c, meet);
        dis_tar = abs(graph.depth[c] - graph.depth[lc_m]);
        dis_mee = abs(graph.depth[meet] - graph.depth[lc_m]);
        ans = max(ans, dis_tar + dis_mee + 1);

        cout << c << " " << meet << " " << lc_m << " " << graph.depth[c] << " " << graph.depth[meet] << " " << graph.depth[lc_m] << " " << dis_tar << " " << dis_mee << "\n";

        cout << ans << "\n";
    }
}
