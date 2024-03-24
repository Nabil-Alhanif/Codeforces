#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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
        vector<ll> group_size;
        vector<ll> connection_size;

        dsu(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->group_size.assign(n, 1);
            this->connection_size.assign(n, 0);
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = this->find(this->parent[n]);
        }

        void combine(ll a, ll b)
        {
            a = this->find(a);
            b = this->find(b);

            this->connection_size[b]++;

            if (a == b)
                return;

            this->parent[a] = b;
            this->group_size[b] += this->group_size[a];
            this->connection_size[b] += this->connection_size[a];
        }
};

ll count(ll n)
{
    return ((n * (n - 1)) / 2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, u, v;
    cin >> n >> m;

    dsu yaDSU(n);
    while (m--) {
        cin >> u >> v;
        u--, v--;
        yaDSU.combine(u, v);
    }

    bool bisa = 1;
    for (int i = 0; i < n; i++) {
        if (i == yaDSU.parent[i]) {
            //cout << i << " i\n";
            bisa &= (yaDSU.connection_size[i] == count(yaDSU.group_size[i]));
        }
    }

    cout << (bisa ? "YES" : "NO") << "\n";
}
