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


struct node
{
    ll people;
    ll happiness;
    ll good_mood;
    ll bad_mood;

    vector<ll> adj;
};

bool dfs(ll idx, ll parent, vector<node> &tree)
{
    bool ret = 1;
    ll bad_mood_count = 0;
    ll original_citizen = tree[idx].people;

    for (auto i:tree[idx].adj) {
        if (i != parent) {
            ret &= dfs(i, idx, tree);
            tree[idx].people += tree[i].people;
            bad_mood_count += tree[i].bad_mood;
        }
    }

    tree[idx].good_mood = tree[idx].people + tree[idx].happiness;
    if (tree[idx].good_mood % 2)
        return 0;
    tree[idx].good_mood /= 2;

    if ((tree[idx].good_mood < 0) || (tree[idx].good_mood > tree[idx].people))
        return 0;

    tree[idx].bad_mood = tree[idx].people - tree[idx].good_mood;
    if (tree[idx].bad_mood > bad_mood_count + original_citizen)
        return 0;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m, u, v;
        cin >> n >> m;

        vector<node> tree(n);
        for (auto &i:tree)
            cin >> i.people;
        for (auto &i:tree)
            cin >> i.happiness;

        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            u--, v--;
            tree[u].adj.push_back(v);
            tree[v].adj.push_back(u);
        }

        cout << (dfs(0, -1, tree) ? "YES" : "NO") << "\n";
    }
}
