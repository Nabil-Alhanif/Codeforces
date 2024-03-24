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

const ll MOD = 1e9 + 7, INF = 1e15;
const double PI = acos(-1);


/* Question specific function and variable */

/* Note to self
 *
 * - Don't use a data structure when you don't need to
 * */


class dsu
{
    public:
        ll size;
        vector<ll> parent;
        vector<vector<ll>> adj_list;

        dsu(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->adj_list.resize(n);
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void merge(ll a, ll b)
        {
            this->adj_list[a].push_back(b);
            this->adj_list[b].push_back(a);
            a = find(a);
            b = find(b);
            if (this->adj_list[a].size() <= 1)
                this->parent[b] = a;
            else this->parent[a] = b;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, u, v, ans = 0;
    cin >> n >> m;

    dsu yaDSU(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        yaDSU.merge(u, v);
    }

    ll alone = 0, cnt = 0;

    set<ll> group;
    for (int i = 0; i < n; i++) {
        if (yaDSU.adj_list[i].size() == 0)
            alone++;
        else if (yaDSU.parent[i] == i)
            group.insert(i);
    }

    vector<bool> visit(n);
    for (auto i:group) {
        ll size = 0;
        bool cycle = 0;

        queue<pair<ll, ll>> q;
        q.push({i, -1});
        visit[i] = 1;

        while (!q.empty()) {
            size++;
            auto [cur, par] = q.front();
            q.pop();

            //cout << cur << " " << par << " cur\n";

            for (auto j:yaDSU.adj_list[cur]) {
                if (!visit[j]) {
                    visit[j] = 1;
                    q.push({j, cur});
                }
                else if (j != par)
                    cycle = 1;
            }
        }

        //cout << i << " " << size << "\n";

        if (cycle)
            ans += size % 2;
        else cnt += size % 2;
    }

    //cout << alone << " " << cnt << "\n";

    if (alone == 0)
        ans += cnt % 2;
    else ans += (cnt + alone) % 2;

    cout << ans << "\n";
}
