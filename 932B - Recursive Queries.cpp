#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000005];
vector<ll> v[10];
ll rek(int n)
{
	if (dp[n])return dp[n];
	ll tmp=1,n2=n;
	while (n)
	{
		ll temp=n%10;
		if (temp)tmp*=temp;
		n/=10;
	}
	dp[n2]=rek(tmp);
	v[dp[n2]].push_back(n2);
	return dp[n2];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i=1;i<10;i++)
	{
		dp[i]=i;
		v[i].push_back(i);
	}
	for (int i=10;i<=1000000;i++)
		rek(i);
	for (int i=0;i<10;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	ll t;
	cin>>t;
	while (t--)
	{
		ll l,r,k;
		cin>>l>>r>>k;
		/*
		cout<<"Test 1: \n";
		for (auto i:v[k])
		{
			if (i>r)break;
			cout<<i<<" ";
		}cout<<"\n";
		cout<<"\nTest 2:\n";
		for (int i=l;i<=r;i++)
		{
			if (dp[i]==k)cout<<i<<" ";
		}cout<<"\n";
		*/
;		ll posl=lower_bound(v[k].begin(),v[k].end(),l)-v[k].begin();
		ll posr=upper_bound(v[k].begin(),v[k].end(),r)-v[k].begin();
		//cout<<posl<<" "<<v[k][posl]<<" "<<posr<<" "<<v[k][posr]<<"\n";
		ll ans=posr-posl;
		cout<<ans<<"\n";
	}
}
