#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        if (
            s.find('1')==string::npos
            ||s.find('2')==string::npos
            ||s.find('3')==string::npos
        )
        {
            cout<<"0\n";
            continue;
        }
        int n=s.size(),ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(3));
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<3;j++)
                dp[i][j]=dp[i-1][j];
            dp[i][s[i-1]-'1']++;
        }/*
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<=n;j++)
                cout<<dp[j][i]<<" ";
            cout<<"\n";
        }*/
        for (int i=0;i<=n-3;i++)
        {
            int l=i+3,r=n,mid;
            while (l<=r)
            {
                mid = (l+r)/2;
                if (
                    dp[mid][0]-dp[i][0]&&
                    dp[mid][1]-dp[i][1]&&
                    dp[mid][2]-dp[i][2]
                )
                {
                    ans=min(ans,mid-i);
                    r=mid-1;
                }
                else l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
}