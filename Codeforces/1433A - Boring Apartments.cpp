#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int ans=10*((n%10)-1);
        int tmp=0;
        while (n)
        {
            tmp++;
            n/=10;
        }
        while (tmp--)
            ans+=tmp+1;
        cout<<ans<<"\n";
    }
}