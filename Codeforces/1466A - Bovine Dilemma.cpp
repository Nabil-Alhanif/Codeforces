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
        ll n;
        cin>>n;
        ll ar[n];
        map<ll,ll>m;
        for (int i=0;i<n;i++)
            cin>>ar[i];
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (ar[j]!=ar[i])
                    m[ar[j]-ar[i]]++;
            }
        }
        cout<<m.size()<<"\n";
    }
}