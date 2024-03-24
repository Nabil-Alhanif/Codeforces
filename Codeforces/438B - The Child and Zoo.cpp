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


struct edge
{
    ll x;
    ll y;
    ll val;
};

class DSU
{
    public:
        ll ans;
        ll size;
        vector<edge> data;
        vector<ll> animals;
        vector<ll> parent;
        vector<ll> node_size;

        DSU(ll n, ll m)
        {
            this->ans = 0;
            this->size = n;
            this->data.resize(m);
            this->animals.resize(n);
            this->parent.resize(n);
            this->node_size.assign(n, 1);

            for (int i = 0; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (this->parent[n] == n)
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void combine(ll a, ll b, ll val)
        {
            ll pa = find(a);
            ll pb = find(b);

            if (pa != pb) {
                //cout << a << " " << b << " " << this->node_size[pa] << " " << this->node_size[pb] << " " << val << "\n";
                ans += this->node_size[pa] * this->node_size[pb] * val;
                this->parent[pb] = pa;
                this->node_size[pa] += this->node_size[pb];
            }
        }
};

bool comp(edge &a, edge &b)
{
    return (a.val > b.val);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Kak Sidiq saya merasa kesal
    // Saya kira f(p, q) itu total binatang dari p ke q
    // Bukan minimalnya
    // AAAAAAAAAAAAAAAAAA

    ll n, m;
    cin >> n >> m;

    DSU yaDSU(n, m);
    for (int i = 0; i < n; i++)
        cin >> yaDSU.animals[i];

    for (auto &i:yaDSU.data) {
        cin >> i.x >> i.y;
        i.x--, i.y--;
        i.val = min(yaDSU.animals[i.x], yaDSU.animals[i.y]);
    }
    sort(yaDSU.data.begin(), yaDSU.data.end(), comp);

    for (auto i:yaDSU.data)
        yaDSU.combine(i.x, i.y, i.val);

    //cout << yaDSU.ans << " ans\n";

    long double ans = yaDSU.ans * 2;
    ans /= (n * (n - 1));

    cout << fixed << setprecision(12) << ans << "\n";
}
