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
        string s;
        cin >> s;

        vector<vector<ll>> last(2, vector<ll>(2, -1));
        ll ans = 0, size = s.size();

        for (int i = 0; i < size; i++)
        {
            ll j = i - 1;
            ll p = i & 1;

            if (s[i] != '1')
                j = min(j, max(last[0][p ^ 1], last[1][p]));
            if (s[i] != '0')
                j = min(j, max(last[0][p], last[1][p ^ 1]));

            ans += i - j;
            if (s[i] != '?')
                last[s[i] - '0'][p] = i;
        }
        
        cout << ans << "\n";
    }
}
