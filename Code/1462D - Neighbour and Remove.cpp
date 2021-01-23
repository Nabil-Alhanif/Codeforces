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
    	//cout<<"T:"<<t<<"\n";
        ll n,tot=0,maks=0;
        cin>>n;
        vector<ll>v(n);
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            tot+=v[i];
            maks=max(maks,v[i]);
        }
        for (ll i=maks;i<=tot;i++)
        {
            if (!(tot%i)&&tot/i<=n)
            {
                bool bisa=1;
                ll locTot=0;
                for (int j=0;j<n;j++)
                {
                    locTot+=v[j];
                    if (locTot==i)
                        locTot=0;
                    else if (locTot>i)
                    {
                        bisa=0;
                        break;
                    }
                }
                if (bisa)
                {
                    cout<<n-(tot/i)<<"\n";
                    break;
                }
            }
        }
    }
}