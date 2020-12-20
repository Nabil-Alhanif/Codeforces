#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a<=b)
        {
            cout<<b<<"\n";
            continue;
        }
        a-=b;
        if (c<=d)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<b+((a+(c-d)-1)/(c-d))*c<<"\n";
    }
}