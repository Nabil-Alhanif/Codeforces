#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[1024];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b;
    while (cin>>a>>b)
    {
        //cout<<a<<" "<<b<<"\n";
        cout<<max(a,b)-min(a,b)<<"\n";
    }
    //return 0;
}