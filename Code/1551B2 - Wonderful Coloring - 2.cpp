#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll tc;
    cin>>tc;

    while(tc--)
    {
        ll n,k;
        cin >> n >> k;

        vector<ll> ar(n);
        vector<pair<ll,ll>> sor(n);
        map<ll,ll> m;

        ll jaw=0;
        for(int i=0;i<n;i++)
        {
            ll a;
            cin >> a;
            sor[i].first = a;
            sor[i].second = i;
            m[a]++;
            if(m[a] <= k)
                jaw++;
        }
        sort(sor.begin(),sor.end());

        map<ll,ll> coba;
        jaw /= k;
        jaw *= k;
        ll idx=1;

        for(int i = 0; i < sor.size(); i++){
            if((coba[sor[i].first] < k) && (idx <= jaw))
            {
                coba[sor[i].first]++;
                ll tmp = idx % k;
                if(tmp == 0)
                    tmp=k;
                ar[sor[i].second] = tmp;
                idx++;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ar[i] << ' ';
        }
        cout<<"\n";
    }
}
