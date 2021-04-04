#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<bool>room(n);
        bool dobel=0;
        for (int i=0;i<n;i++)
        {
            ll tmp;
            cin>>tmp;
            tmp%=n;
            if (room[(i+n+tmp)%n])
                dobel=1;
            room[(i+n+tmp)%n]=1;
        }
        if (dobel)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
}