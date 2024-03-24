#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        for (int i=0;i<n;i++)
            cin>>ar[i];
        int minPref[n],minSuff[n],nMin=ar[0],nIDMin=0;
        minPref[0]=0, minSuff[n-1]=n-1;
        for (int i=1;i<n;i++)
        {
            if (nMin>ar[i])
            {
                nIDMin=i;
                nMin=ar[i];
            }
            minPref[i]=nIDMin;
        }
        nMin=ar[n-1],nIDMin=n-1;
        for (int i=n-2;i>=0;i--)
        {
            if (nMin>ar[i])
            {
                nIDMin=i;
                nMin=ar[i];
            }
            minSuff[i]=nIDMin;
        }
        /*
        for (int i=0;i<n;i++)
            cout<<ar[i]<<" ";
        cout<<"\n";
        for (int i=0;i<n;i++)
            cout<<minPref[i]<<" ";
        cout<<"\n";
        for (int i=0;i<n;i++)
            cout<<minSuff[i]<<" ";
        cout<<"\n";
        */
        bool find=0;
        for (int i=1;i<n-1;i++)
        {
            if (minPref[i]!=i&&minSuff[i]!=i)
            {
                find=1;
                cout<<"YES\n";
                cout<<minPref[i]+1<<" "<<i+1<<" "<<minSuff[i]+1<<"\n";
                break;
            }
        }
        if (!find)
            cout<<"NO\n";
    }
}