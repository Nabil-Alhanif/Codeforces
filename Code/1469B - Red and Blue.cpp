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
        int a=0,b=0;
        int n;
        cin>>n;
        int red[n];
        for (int i=0;i<n;i++)
            cin>>red[i];
        int m;
        cin>>m;
        int blue[m];
        for (int i=0;i<m;i++)
            cin>>blue[i];
        a=max(a,red[0]);
        b=max(b,blue[0]);
        for (int i=1;i<n;i++)
        {
            red[i]+=red[i-1];
            a=max(a,red[i]);
        }
        for (int i=1;i<m;i++)
        {
            blue[i]+=blue[i-1];
            b=max(b,blue[i]);
        }
        cout<<a+b<<"\n";
    }
}