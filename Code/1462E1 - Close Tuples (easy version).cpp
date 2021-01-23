#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,ans=0;
        cin>>n;
        ll ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        /*cout<<"\n";
        cout<<"ar: ";
        for (int i=0;i<n;i++)
            cout<<ar[i]<<" ";
        cout<<"\n";*/
        for (int i=2;i<n;i++)
        {
            ll low=lower_bound(ar,ar+n,ar[i]-2)-ar;
            ll com=i-low;
            if (com>=2)
                ans+=(com*(com-1))/2;
        }
        cout<<ans<<"\n";
    }
}