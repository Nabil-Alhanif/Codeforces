#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>m;

ll dp(ll i)
{
	if (m[i]!=0)return m[i];
	return ((m[i]=((dp(i-1)+dp(i-2))%1000000007)));
}

int main()
{
	m[0]=1;
	m[1]=1;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;ll u=0,n=0,size,ans=1;
	cin>>s;
	size=s.size();
	for (int i=0;i<size;i++)
	{
		//cout<<"i "<<i<<"\n";
		if (s[i]=='u')u++;
		if (s[i]!='u'||i==size-1)
		{
			//cout<<u<<" "<<ans<<"\n";
			ans*=dp(u);
			ans%=1000000007;
			u=0;
		}
		if (s[i]=='n')n++;
		if (s[i]!='n'||i==size-1)
		{
			//cout<<n<<" "<<ans<<"\n";
			ans*=dp(n);
			ans%=1000000007;
			n=0;
		}
		if (s[i]=='m'||s[i]=='w')
		{
			ans=0;
			break;
		}
	}
	ans%=1000000007;
	cout<<ans<<"\n";
}
