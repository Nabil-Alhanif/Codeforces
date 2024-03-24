#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,tt=0;
        cin>>n;
        int ar[n],bar[n];
        bool a=1,b=0,c=0;
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
            if (tt>ar[i])
                a=0;
            tt=ar[i];
        }
        for (int i=0;i<n;i++)
        {
            cin>>bar[i];
            if (bar[i]==1)
                b=1;
            else c=1;
        }
        if (a||(b&&c))
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}