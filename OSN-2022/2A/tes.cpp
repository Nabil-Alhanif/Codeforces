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


class DSU
{
    public:
        vector<ll> parent;

        DSU(ll n)
        {
            this->parent.resize(n);
            for (ll i = 0; i < n; i++)
                this->parent[i] = i;
        }

        ll find(ll n)
        {
            if (this->parent[n] == n)
                return n;
            return this->parent[n] = find(this->parent[n]);
        }

        bool combine(ll a, ll b)
        {
            ll pa = find(a), pb = find(b);
            if (pa != pb) {
                this->parent[pa] = pb;
                return 1;
            }
            return 0;
        }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, q, u, v;
    cin >> n >> m >> q;

    ll maks = (n * (n + 1)) / 2;
    if (m >= maks)
        return cout << "0\n", 0;

    vector<ll> height(n);
    for (ll i = 0; i < n; i++)
        cin >> height[i];

    DSU yaDSU(n);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        yaDSU.combine(u, v);
    }

    vector<ll> group_lead;
    map<ll, vector<pair<ll, pair<ll, ll>>>> con;
    for (ll i = 0; i < n; i++) {
        ll pi = yaDSU.find(i);
        if (pi == i)
            group_lead.push_back(i);
        con[pi].push_back({height[i], {pi, i}});
    }

    ll group_count = group_lead.size();
    ll need_bridge = group_count - 1;
    ll need_city = need_bridge * 2;

    if (n < need_city)
        return cout << "-1\n", 0;

    if (group_count <= 1)
        return cout << "0\n", 0;

    need_city = max((ll)0, need_city - group_count);

    map<ll, vector<ll>> hitung;
    map<ll, ll> jumlah;

    vector<pair<ll, ll>> out;

    vector<ll> urutan;
    vector<pair<ll, pair<ll, ll>>> con2;
    for (auto &i:con) {
        sort(i.se.begin(), i.se.end());
        urutan.push_back(i.se[0].se.se);
        jumlah[i.se[0].se.fi]++;

        ll ss = i.se.size();
        for (ll j = 1; j < ss; j++)
            con2.push_back(i.se[j]);
    }
    sort(con2.begin(), con2.end());

    for (auto i:con2) {
        if (jumlah[i.se.fi] >= need_bridge)
            continue;

        hitung[i.se.fi].push_back(i.se.se);
        jumlah[i.se.fi]++;

        need_city--;
        if (need_city == 0)
            break;
    }

    if (need_city != 0)
        return cout << "-1\n", 0;

    ll ans = 0;
    for (auto i:hitung) {
        for (auto j:i.se) {
            ans += height[j];
            urutan.push_back(j + 1);
        }
    }

    cout << ans << "\n";
    cout << need_bridge << "\n";
    for (ll i = 0; i < need_bridge; i++)
        cout << urutan[i] << " " << urutan[i + need_bridge] << "\n";
}
