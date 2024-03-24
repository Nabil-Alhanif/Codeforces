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


class dsu
{
    public:
        ll size;
        vector<ll> parent;

        dsu(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        bool combine(ll a, ll b)
        {
            a = find(a);
            b = find(b);

            if (a != b) {
                this->parent[a] = b;
                return true;
            }
            return false;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m1, m2, u, v;
    cin >> n >> m1 >> m2;

    dsu mocha(n);
    dsu diana(n);

    for (int i = 0; i < m1; i++) {
        cin >> u >> v;
        u--, v--;
        mocha.combine(u, v);
    }

    for (int i = 0; i < m2; i++) {
        cin >> u >> v;
        u--, v--;
        diana.combine(u, v);
    }

    vector<pair<ll, ll>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool separated_in_mocha, separated_in_diana;
            separated_in_mocha = (mocha.find(i) != mocha.find(j));
            separated_in_diana = (diana.find(i) != diana.find(j));

            if (separated_in_mocha && separated_in_diana) {
                mocha.combine(i, j);
                diana.combine(i, j);
                ans.push_back({i + 1, j + 1});
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i.fi << " " << i.se << "\n";
}
