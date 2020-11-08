#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b,n,ans=0;
        cin>>a>>b>>n;
        while (a<=n&&b<=n)
        {
            if (a>b)
                swap(a,b);
            a+=b;
            ans++;
        }
        cout<<ans<<"\n";
    }
}