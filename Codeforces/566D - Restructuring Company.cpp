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


class DSU
{
    public:
        ll size;
        vector<ll> parent;

        DSU(ll n)
        {
            this->size = n;
            this->parent.resize(n);

            for (int i = 0; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (this->parent[n] == n)
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void combine(ll a, ll b)
        {
            ll pa = find(a);
            ll pb = find(b);

            if (a != b)
                this->parent[pa] = pb;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q, t, x, y;
    cin >> n >> q;

    vector<ll> next_seg(n);
    for (int i = 0; i < n; i++)
        next_seg[i] = i + 1;

    DSU yaDSU(n);
    while (q--) {
        cin >> t >> x >> y;
        x--, y--;

        if (t == 1) {
            yaDSU.combine(x, y);
        }
        else if (t == 2) {
            ll first_par = yaDSU.find(x);
            ll i = x, next_pos;
            while (i <= y) {
                yaDSU.combine(first_par, i);
                next_pos = next_seg[i];
                next_seg[i] = next_seg[y];
                i = next_pos;
            }
        }
        else {
            ll px = yaDSU.find(x);
            ll py = yaDSU.find(y);

            cout << ((px == py) ? "YES\n" : "NO\n");
        }
    }
}
