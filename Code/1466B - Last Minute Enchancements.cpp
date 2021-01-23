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
        {
            cin>>ar[i];
            m[ar[i]]++;
        }
        sort(ar,ar+n);
        for (int i=0;i<n;i++)
        {
            if (m[ar[i]]>1)
            {
                m[ar[i]]--;
                m[ar[i]+1]++;
            }
        }
        cout<<m.size()<<"\n";
    }
}