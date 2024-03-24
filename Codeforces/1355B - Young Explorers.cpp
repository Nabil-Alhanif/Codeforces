#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,ans=0;
        cin>>n;
        int ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        int curTot=0;
        for (int i=0;i<n;i++)
        {
            curTot++;
            if (ar[i]<=curTot)
            {
                ans++;
                curTot=0;
            }
        }
        cout<<ans<<"\n";
    }
}