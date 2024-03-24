#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll tot=a+b+c;
        if (tot%9)
        {
            cout<<"NO\n";
            continue;
        }
        tot/=9;
        if (a<tot||b<tot||c<tot)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}