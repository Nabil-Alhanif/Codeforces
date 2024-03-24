#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;


class DSU
{
    public:
        ll size;
        vector<ll> parent;
        vector<ll> val;

        DSU(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->val.resize(n);
        }

        ll find(ll n)
        {
            if (n == this->parent[n])
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        void combine(ll a, ll b)
        {
            ll pa = find(a), pb = find(b);
            if (pa != pb) {
                this->parent[pa] = pb;
                this->val[pb] += this->val[pa];
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> beauty(n);
    for (int i = 0; i < n; i++)
        cin >> beauty[i];

    vector<ll> harta(n);
    for (int i = 0; i < n; i++)
        cin >> harta[i];

    DSU yaDSU(n);
    for (int i = 0; i < n; i++)
        yaDSU.val[i] = harta[i];

    /*
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((beauty[i] ^ beauty[j]) > max(beauty[i], beauty[j]))
                yaDSU.combine(i, j);
        }
    }
    */

    for (int i = 0; i < n; i++)
        cout << harta[i] << "\n";
}
