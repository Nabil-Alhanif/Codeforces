#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,m,a;
        cin >> n >> m >> a;
        ll pu=(n*m)/2, hi=(n*m)/2;
        if(m%2==1){
            pu=(m+1)*n/2;
            hi=n*m-pu;
        }
        pu-=a; hi-=a;
        if(a==0&&n%2==1) cout<<"NO\n";
        else if((a*2)<m&&n%2==1) cout<<"NO\n";
        else if(pu%2==0&&hi%2==0&&pu>=0&&hi>=0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
