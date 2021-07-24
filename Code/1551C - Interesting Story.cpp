#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        vector<ll> a;
        vector<ll> b;
        vector<ll> c;
        vector<ll> d;
        vector<ll> e;

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            ll bana=0, banb=0, banc=0, band=0, bane=0;
            for(int j = 0; j < s.length(); j++)
            {
                if(s[j]=='a')bana++;
                if(s[j]=='b')banb++;
                if(s[j]=='c')banc++;
                if(s[j]=='d')band++;
                if(s[j]=='e')bane++;
            }
            
            ll tots=s.length();
            a.push_back(bana-(tots-bana));
            b.push_back(banb-(tots-banb));
            c.push_back(banc-(tots-banc));
            d.push_back(band-(tots-band));
            e.push_back(bane-(tots-bane));
        }

        ll tmp = 0,jaw = 0;
        sort(a.rbegin(), a.rend());
        for(ll i = 0; i < n; i++)
        {
            tmp += a[i];
            if(tmp <= 0)
                break;
            jaw = max(jaw, i + 1);
        }

        tmp = 0;
        sort(b.rbegin(), b.rend());
        for(ll i = 0; i < n; i++){
            tmp += b[i];
            if(tmp <= 0)
                break;
            jaw = max(jaw, i + 1);
        }

        tmp = 0;
        sort(c.rbegin(), c.rend());
        for(ll i = 0; i < n; i++){
            tmp += c[i];
            if(tmp <= 0)
                break;
            jaw = max(jaw, i + 1);
        }

        tmp = 0;
        sort(d.rbegin(), d.rend());
        for(ll i = 0; i < n; i++){
            tmp += d[i];
            if(tmp <= 0)
                break;
            jaw = max(jaw, i + 1);
        }

        tmp = 0;
        sort(e.rbegin(), e.rend());
        for(ll i = 0; i < n; i++){
            tmp += e[i];
            if(tmp <= 0)
                break;
            jaw = max(jaw, i + 1);
        }
        cout << jaw << "\n";
    }
}
