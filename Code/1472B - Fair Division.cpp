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
        ll n,tot=0;
        cin>>n;
        bool bisa=1;
        ll a=0,b=0;
        for (int i=0;i<n;i++)
        {
            ll tmp;
            cin>>tmp;
            tot+=tmp;
            if (tmp==1)
                a++;
            else b++;
        }
        if (tot%2)
            bisa=0;
        b%=2;
        if (b&&(a<=1))
            bisa=0;
        if (bisa)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}