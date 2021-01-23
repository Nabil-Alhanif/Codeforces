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
        int n,k,uj;
        cin>>n;
        vector<int>v(n);
        for (int i=0;i<n;i++)
            cin>>v[i];
        cin>>k;
        uj=v[k-1];
        int ans=1;
        for (int i=0;i<n;i++)
            if (v[i]<uj)
                ans++;
        cout<<ans<<"\n";
    }
}