#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,ber=0,ans=0;
        cin>>n>>m;
        ll k[n], prize[m];
        for (int i=0;i<n;i++)
        {
            cin>>k[i];
            k[i]--;
        }
        for (int i=0;i<m;i++)
            cin>>prize[i];
        sort(k,k+n);
        /*
        cout<<"K[i]: ";
        for (int i=0;i<n;i++)
            cout<<k[i]<<" ";
        cout<<"\n";
        */
        int j=0;
        for (int i=n-1;i>=0&&k[i]>=j;i--)
        {
            ber++;
            j++;
            //cout<<i<<" "<<k[i]<<" "<<j<<" Itr\n";
        }
        for (int i=0;i<ber;i++)
        {
            //cout<<prize[i]<<" ";
            ans+=prize[i];
        }
        for (int i=0;i<n-ber;i++)
        {
            ans+=prize[k[i]];
            //cout<<prize[k[i]]<<" ";
        }
        //cout<<"\n";
        cout<<ans<<"\n";
    }
}