#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, ans = 0;
        cin >> n;

        vector<ll> graph;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;

            if (a < 0)
                ans += a;
            else
                graph.push_back(a);
        }

        sort(graph.begin(), graph.end());
        for (ll i = 1; i < (ll)graph.size(); i++)
        {
            if (i > 1)
                ans -= (((i - 1) * graph[i] - graph[i-2]));
            graph[i] += graph[i-1];
        }
        
        cout << ans << "\n";
    }
}

