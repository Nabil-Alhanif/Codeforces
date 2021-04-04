#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        map<int,int>m;
        while (a--)
        {
            int tmp;
            cin>>tmp;
            m[tmp]++;
        }
        int ans=0;
        while (b--)
        {
            int tmp;
            cin>>tmp;
            if (m[tmp])
                ans=(!ans?tmp:min(ans,tmp));
        }
        if (!ans)
            cout<<"NO\n";
        else
            cout<<"YES\n1 "<<ans<<"\n";
    }
}