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
        vector<ll> group_size;

        dsu(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->group_size.assign(n, 1);
        }

        ll find(ll n)
        {
            if (this->parent[n] == n)
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void merge(ll a, ll b)
        {
            a = find(a);
            b = find(b);

            if (a != b) {
                this->parent[a] = b;
                this->group_size[a] += this->group_size[b];
                this->group_size[b] = this->group_size[a];
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, u, v;
        cin >> n;

        bool ans = 1;

        dsu yaDSU(n);
        vector<ll> connected(n);

        for (int i = 0; i < n; i++) {
            cin >> u >> v;
            if (u == v)
                ans = 0;

            u--, v--;
            yaDSU.merge(u, v);

            connected[u]++;
            connected[v]++;

            ans &= ((connected[u] <= 2) && (connected[v] <= 2));
        }

        for (int i = 0; i < n; i++) {
            if (yaDSU.parent[i] == i) {
                //cout << i << ": " << yaDSU.group_size[i] << "\n";
                ans &= (yaDSU.group_size[i] % 2 == 0);
            }
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }
}
