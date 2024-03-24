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


class graph
{
    public:
        ll size;
        vector<vector<ll>> adj_list;
        map<ll, ll> hash;
        map<ll, ll> color;

        graph(ll n)
        {
            this->size = n;
            this->adj_list.resize(n);

            ll u, v;
            for (int i = 1; i < n; i++) {
                cin >> u >> v;
                u--, v--;
                this->adj_list[u].push_back(v);
                this->adj_list[v].push_back(u);
            }

            dfs(0, -1, 0, 0);
        }

        void dfs(ll idx, ll parent, ll depth, ll cur_color)
        {
            //cout << idx << " " << parent << " " << depth << " " << cur_color << "\n";
            this->hash[idx] = cur_color;

            ll cur_size = this->adj_list[idx].size();
            bool cabang = cur_size > 2;

            for (int i = 0, cnt = 1; i < cur_size; i++) {
                if (this->adj_list[idx][i] == parent)
                    continue;

                if (cabang) {
                    dfs(this->adj_list[idx][i], idx, depth + 1, cur_color + cnt);
                    this->color[cur_color + cnt] = depth + 1;
                    //cout << "Cabang: " << this->adj_list[idx][i] << " " << idx << " " << depth + 1 << " " << cur_color + cnt<< "\n";
                    cnt++;
                }
                else dfs(this->adj_list[idx][i], idx, depth, cur_color);
            }
        }

        void solve(ll n)
        {
            bool flag = 1;
            bool doubled = 0;

            set<ll> col;
            for (int i = 0, x; i < n; i++) {
                cin >> x;
                col.insert(this->hash[x - 1]);
            }

            map<ll, ll> check;
            for (auto i:col) {
                check[this->color[i]]++;
                if (check[this->color[i]] > 2) {
                    if (!doubled)
                        doubled = 1;
                    else flag = 0;
                }
            }

            cout << (flag ? "YES\n" : "NO\n");
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q, k;
    cin >> n;

    graph tree(n);

    for (int i = 0; i < n; i++)
        cout << "Idx: " << i << " tree color: " << tree.hash[i] << " color depth: " << tree.color[tree.hash[i]] << "\n";

    cin >> q;
    while (q--) {
        cin >> k;
        tree.solve(k);
    }
}
