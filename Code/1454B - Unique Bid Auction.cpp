#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,ans=-1;
        cin>>n;
        map<int,pair<int,int>>bid;
        for (int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            bid[tmp]={i+1,bid[tmp].second+1};
        }
        for (auto i:bid)
            if (i.second.second==1)
            {
                ans=i.second.first;
                break;
            }
        cout<<ans<<"\n";
    }
}