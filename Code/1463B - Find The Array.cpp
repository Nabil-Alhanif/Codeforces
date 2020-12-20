#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastExp(ll a, ll b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    if (b%2)
        return fastExp(a,b/2)*fastExp(a,b/2)*a;
    else return fastExp(a,b/2)*fastExp(a,b/2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        while (n--)
        {
            ll tmp;
            cin>>tmp;
            ll tmpp=log2(tmp);
            //cout<<tmpp<<"\n";
            cout<<fastExp(2,tmpp)<<" ";
        }
        cout<<"\n";
    }
}