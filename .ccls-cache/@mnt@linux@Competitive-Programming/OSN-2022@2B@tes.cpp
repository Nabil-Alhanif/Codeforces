#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;

const ll INF = 1e18 + 5;


int main()
{
    ll n;
    cin >> n;

    indexed_set<ll> tt;
    vector<ll> type(n);
    for (ll i = 0; i < n; i++) {
        cin >> type[i];
        tt.insert(type[i]);
    }

    vector<ll> weight(n);
    for (ll i = 0; i < n; i++)
        cin >> weight[i];

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    ll ans = INF;

    ll fruit_type = tt.size();

    vector<bool> visit(n, 0);

    priority_queue<pair<pair<ll, ll>, pair<ll, ll>>, vector<pair<pair<ll, ll>, pair<ll, ll>>>, greater<pair<pair<ll, ll>, pair<ll, ll>>>> pq;

    vector<vector<ll>> adj_list(fruit_type);
    for (int i = 0; i < n; i++) {
        type[i] = tt.order_of_key(type[i]) + 1;
        adj_list[type[i] - 1].push_back(i);

        if (type[i] == 1)
            pq.push({{v[i], weight[i]}, {1, i}});
    }

    ll energy, b, t, p;
    while (!pq.empty()) {
        energy = pq.top().fi.fi;
        b = pq.top().fi.se;
        t = pq.top().se.fi;
        p = pq.top().se.se;
        pq.pop();

        //cout << energy << " " << b << " " << t << " " << p << "\n";

        if (visit[p])
            continue;
        visit[p] = 1;

        if (t == fruit_type) {
            ans = min(ans, energy);
            continue;
        }

        for (auto i:adj_list[t]) {
            if (visit[i])
                continue;

            ll new_energy = energy + (abs(i - p) * b) + (v[i] * b);
            ll new_weight = weight[i] * b;
            pq.push({{new_energy, new_weight}, {t + 1, i}});
        }
    }

    cout << ans << "\n";
}
