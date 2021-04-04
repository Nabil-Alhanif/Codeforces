#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, k, ans = 0;
        cin >> a >> b >> k;
        map<ll, ll> boys, girls;
        pair<ll, ll> pairs[k];
        for (int i=0; i<k; i++)
        {
            int tmp;
            cin >> tmp;
            boys[tmp]++;
            pairs[i].first = tmp;
        }
        for (int i=0; i<k; i++)
        {
            int tmp;
            cin >> tmp;
            girls[tmp]++;
            pairs[i].second = tmp;
        }
        for (int i=0; i<k; i++)
        {
            ll left = (boys[pairs[i].first]+girls[pairs[i].second]-1);
            //cout << left << "\n";
            ans += k-left;
        }
        ans/=2;
        cout << ans << "\n";
    }
}