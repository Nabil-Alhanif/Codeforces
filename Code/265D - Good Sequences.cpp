#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,ans=1;
    cin>>n;
    vector<ll>dp(1e+5);
    for (int i=0;i<n;i++)
    {
        ll cur;
        cin>>cur;
        ll curAns=0;
        vector<ll>fact;
        for (int j=2;j*j<=cur;j++)
        {
            if (!(cur%j))
            {
                curAns=max(curAns,dp[j]);
                fact.push_back(j);
            }
            while (!(cur%j))
                cur/=j;
        }
        if (cur>1)
        {
            curAns=max(curAns,dp[cur]);
            fact.push_back(cur);
        }
        curAns++;
        for (auto j:fact)
            dp[j]=curAns;
    }
    for (auto i:dp)
        ans=max(ans,i);
    cout<<ans<<"\n";
}