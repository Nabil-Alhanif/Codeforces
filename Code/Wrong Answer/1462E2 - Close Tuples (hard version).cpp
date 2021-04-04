#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,k,ans=0;
        cin>>n>>m>>k;
        m--;
        ll ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        /*cout<<"\n";
        cout<<"ar: ";
        for (int i=0;i<n;i++)
            cout<<ar[i]<<" ";
        cout<<"\n";*/
        for (int i=m;i<n;i++)
        {
            ll low=lower_bound(ar,ar+n,ar[i]-k)-ar;
            //cout<<i<<" "<<ar[i]<<" "<<low<<" "<<ar[low]<<" ";
            ll com=i-low;
            if (com>=m)
            {
                // Tinggal kombinasi nya aja
            }
            //cout<<"\n";
        }
        cout<<ans<<"\n";
    }
}