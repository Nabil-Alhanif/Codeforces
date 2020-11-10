#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,ans=1;
        cin>>n;
        int ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        for (int i=n-1;i>=0;i--)
            if (ar[i]<=i+1)
            {
                ans+=i+1;
                break;
            }
        cout<<ans<<"\n";
    }
}