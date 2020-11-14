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
        int cnt=0;
        bool b=0,a=1;
        for (int i=0;i<n;i++)
        {
            b=(b||ar[i]);
            if (ar[i]==0&&b)
            {
                //cout<<"C0 "<<i<<" "<<cnt<<"\n";
                cnt++;
                a=1;
            }
            if ((ar[i]==1)&&a)
            {
                //cout<<"C1 "<<i<<" "<<cnt<<"\n";
                ans+=cnt;
                cnt=0;
                a=0;
            }
        }
        cout<<ans<<"\n";
    }
}