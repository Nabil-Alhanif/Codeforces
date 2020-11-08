#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        if (n<=2)
        {
            cout<<"1\n";
            continue;
        }
        n-=2;
        int ans=n/x+1;
        ans+=(n%x?1:0);
        cout<<ans<<"\n";
    }
}