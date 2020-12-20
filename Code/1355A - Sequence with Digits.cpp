#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll a,k;
        cin>>a>>k;
        k--;
        while (k--)
        {
            ll mins=10,maks=0,b=a;
            while (b)
            {
                ll tmp=b%10;
                mins=min(mins,tmp);
                maks=max(maks,tmp);
                b/=10;
            }
            a+=mins*maks;
            if (!(mins)||!(maks))
                break;
        }
        cout<<a<<"\n";
    }
}