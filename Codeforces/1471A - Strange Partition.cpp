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
        ll n,x;
        cin>>n>>x;
        ll mins=0, maks=0;
        for (int i=0;i<n;i++)
        {
            ll tmp;
            cin>>tmp;
            mins+=tmp;
            maks+=(tmp+x-1)/x;
        }
        mins=(mins+x-1)/x;
        cout<<mins<<" "<<maks<<"\n";
    }
}