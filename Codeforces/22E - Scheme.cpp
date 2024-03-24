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
        vector<ll> heads;
        vector<ll> into;
        vector<ll> order;
        vector<ll> parent;
        vector<ll> tail;
        vector<bool> vis;
        vector<pair<ll, ll>> ans;

        Solve()
        {
            cin >> this->n;

            this->adj_list.resize(n);
            this->into.resize(n);
            this->parent.resize(n);
            this->tail.resize(n);
            this->vis.resize(n);

            for (int i = 0; i < n; i++) {
                this->parent[i] = i;
                this->tail[i] = i;
            }

            ll v;
            for (int i = 0; i < this->n; i++) {
                cin >> v;
                v--;
                this->adj_list[i].push_back(v);
            }

            for (int i = 0; i < n; i++) {
                if (!this->vis[i]) {
                    this->vis[i] = 1;
                    dfs(i);
                    this->order.push_back(i);
                }
            }

            /*
            for (auto i:this->order)
                cout << i << "\n";

            for (int i = 0; i < n; i++)
                cout << "Parent of: " << i << " is " << find(i) << "\n";
            */

            for (int i = 0; i < n; i++) {
                if (this->into[i] == 0) {
                    this->tail[find(i)] = i;
                    //cout << i << " is a tail of " << find(i) << "\n";
                }
            }

            for (int i = 0; i < n; i++)
                this->vis[i] = 0;

            for (int i = 0; i < n; i++) {
                if (find(i) == i)
                    this->heads.push_back(i);
            }

            /*
            for (auto i:this->order) {
                if (!this->vis[i]) {
                    this->heads.push_back(i);
                    this->vis[i] = 1;
                    dfs2(i);
                }
            }
            */

            /*
            for (auto i:this->heads)
                cout << i << " is a head\n";
            */

            ll head_count = this->heads.size();
            for (int i = 0; i < head_count - 1; i++) {
                if (this->heads[i] != this->tail[this->heads[i + 1]]) {
                    this->ans.push_back({this->heads[i], this->tail[this->heads[i + 1]]});
                    this->into[this->tail[this->heads[i + 1]]]++;
                }
            }
            if (this->heads[head_count - 1] != this->tail[this->heads[0]]) {
                this->ans.push_back({this->heads[head_count - 1], this->tail[this->heads[0]]});
                this->into[this->tail[this->heads[0]]]++;
            }

            for (int i = 0; i < n; i++) {
                if (this->into[i] == 0)
                    this->ans.push_back({find(i), i});
            }

            cout << ans.size() << "\n";
            for (auto i:ans)
                cout << i.fi + 1 << " " << i.se + 1 << "\n";
        }

        void dfs(ll cur)
        {
            this->vis[cur] = 1;

            for (auto i:adj_list[cur]) {
                this->into[i]++;
                combine(cur, i);
                if (!this->vis[i]) {
                    this->vis[i] = 1;
                    dfs(i);
                    this->order.push_back(i);
                }
            }
        }

        void dfs2(ll cur)
        {
            this->vis[cur] = 1;
            for (auto i:adj_list[cur]) {
                if (!this->vis[i]) {
                    this->vis[i] = 1;
                    dfs2(i);
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
