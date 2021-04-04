#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main()
{
	ll n,l,r,ans=0;
	cin>>n>>l>>r;
	ll n3,n31,n32,lm3,rm3;
	n3=r/3-l/3;
	if (!(l%3))n3++;
	lm3=l%3;
	rm3=r%3;
	n31=n3-1;
	n32=n3-1;
	if (lm3==1)
		n31++;
	if (lm3>0)
		n32++;
	if (rm3>0)
		n31++;
	if (rm3>1)
		n32++;
	ll n312=n31*n32;
	n312%=MOD;
	//cout<<n3<<" "<<n31<<" "<<n32<<" "<<n312<<"\n";
	vector<vector<ll> > dp(n+1,vector<ll>(3));
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		dp[i][0] = (dp[i-1][0] * n3 + dp[i-1][1] * n32 + dp[i-1][2] * n31)%MOD;
		dp[i][1] = (dp[i-1][0] * n31 + dp[i-1][1] * n3 + dp[i-1][2] * n32)%MOD;
		dp[i][2] = (dp[i-1][0] * n32 + dp[i-1][1] * n31 + dp[i-1][2] * n3)%MOD;
	}
	cout<<dp[n][0]<<"\n";
}
