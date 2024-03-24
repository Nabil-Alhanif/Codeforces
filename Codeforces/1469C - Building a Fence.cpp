#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,k,maks=0;
        cin>>n>>k;
        vector<ll>v(n);
        for (int i=0;i<n;i++)
            cin>>v[i];
        ll bawah=v[0],atas=v[0];
        bool bisa=1;
        for (int i=1;i<n;i++)
        {
            bawah=max(bawah-(k-1),v[i]);
            atas=min(atas+(k-1),v[i]+(k-1));
            if (bawah>atas)
            {
                bisa=0;
                break;
            }
        }
        if (v[n-1]<bawah||v[n-1]>atas)
            bisa=0;
        if (bisa)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}