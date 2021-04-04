#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		string s;ll n, ans=0, cur=0;
		cin>>n>>s;
		vector<ll>pref(n+1), dp(n+1);
		for (int i=0;i<n;i++)
		{
			pref[i+1]=pref[i]+(s[i]-'0');
		}
		for (int i=0;i<n;i++)
		{
			cout<<pref[i+1]<<" ";
		}cout<<"\n";
	}
}
