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
        ll n;
        cin>>n;
        string s="";
        int i;
        for (i=9;i>0;i--)
        {
            if (n<i)
                break;
            n-=i;
            s=string(1,'0'+i)+s;
            //cout<<n<<" "<<i<<" "<<s<<"\n";
        }
        if (i==0&&n)
            cout<<"-1\n";
        else
            cout<<(n==0?"":string(1,'0'+n))<<s<<"\n";
    }
}