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
        string s;
        cin>>s;
        bool b=0;
        string ss="2020";
        for (int i=0;i<=4;i++)
        {
            bool c=1;
            //cout<<"\n";
            for (int j=0;j<i;j++)
            {
                //cout<<j<<" ";
                if (s[j]!=ss[j])
                    c=0;
            }
            for (int k=1;k<=4-i;k++)
            {
                //cout<<n-k<<" ";
                if (s[n-k]!=ss[4-k])
                    c=0;
            }
            //cout<<c<<"\n";
            b|=c;
        }
        if (!b)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
}