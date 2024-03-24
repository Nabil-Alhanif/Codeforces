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
        ll size;
        vector<ll> parent;
        vector<ll> group_size;

        vector<set<ll>> connected;
        vector<map<ll, ll>> prices;

        DSU(ll n)
        {
            this->size = n;
            this->parent.resize(n);
            for (int i = 0; i < n; i++)
                this->parent[i] = i;
            this->group_size.assign(n, 1);

            this->connected.resize(n);
            this->prices.resize(n);
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
                this->group_size[pb] += this->group_size[pa];
            }
        }

        void combine2(ll a, ll b, ll w)
        {
            ll pa = find(a), pb = find(b);
            if (pa != pb) {
                this->connected[pa].insert(pb);
                this->connected[pb].insert(pa);

                if (this->prices[pa].contains(pb)) {
                    if (w < this->prices[pa][pb])
                        this->prices[pa][pb] = w;
                }
                else this->prices[pa][pb] = w;

                if (this->prices[pb].contains(pa)) {
                    if (w < this->prices[pb][pa])
                        this->prices[pb][pa] = w;
                }
                else this->prices[pb][pa] = w;
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, u, v, t, w;
    cin >> n >> m;

    vector<pair<pair<ll, ll>, ll>> plane;

    DSU yaDSU(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t >> w;
        if (t == 0)
            yaDSU.combine(u, v);
        else plane.push_back({{u, v}, w});
    }

    for (auto i:plane)
        yaDSU.combine2(i.fi.fi, i.fi.se, i.se);

    vector<ll> group_lead;
    for (int i = 0; i < n; i++) {
        if (yaDSU.parent[i] == i)
            group_lead.push_back(i);
    }

    ll group_count = group_lead.size();
    vector<pair<ll, ll>> cnt;
    for (int i = 0; i < group_count; i++) {
        ll j = group_lead[i];
        if (yaDSU.connected[j].size() == group_count - 1) {
            ll price = 0;
            for (int k = 0; k < group_count; k++)
                price = max(price, yaDSU.prices[j][group_lead[k]]);
            cnt.push_back({price, yaDSU.group_size[j]});
        }
    }

    vector<ll> ans;
    for (auto i:cnt) {
        for (int j = 0; j < i.se; j++)
            ans.push_back(i.fi);
    }
    sort(ans.begin(), ans.end());

    ll size = ans.size();
    for (int i = 0; (i < size) && (i < n); i++)
        cout << ans[i] << " ";
    for (int i = size; i < n; i++)
        cout << "-1 ";
    cout << "\n";
}
