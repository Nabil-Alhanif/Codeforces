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
        ll w,h,n;
        cin>>w>>h>>n;
        ll t1=1,t2=1;
        while (!(w%2))
        {
            w/=2;
            t1*=2;
        }
        while (!(h%2))
        {
            h/=2;
            t2*=2;
        }
        if (t1*t2>=n)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}