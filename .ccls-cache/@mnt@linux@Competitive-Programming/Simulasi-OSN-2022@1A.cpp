#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;

class DSU
{
    public:
        vector<ll> parent;

        DSU(ll n)
        {
            this->parent.resize(n + 1);
            for (int i = 1; i <= n; i++)
                this->parent[i] = i;
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
            if (pa != pb)
                this->parent[pa] = pb;
        }
};

int main()
{
    ll n, m, x;
    cin >> n >> m;

    DSU yaDSU(n);

    vector<ll> par(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> par[i];

    vector<ll> ans;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        x = yaDSU.find(x);
        if (x == 0)
            ans.push_back(i);
        yaDSU.combine(x, yaDSU.find(par[x]));
    }

    cout << ans.size() << "\n";
    for (auto i:ans)
        cout << i << " ";
    cout << "\n";
}
