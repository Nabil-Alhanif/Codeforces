#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,ans=0;string s;
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		if(i%2)
		{
			if(s[i]=='a'&&s[i-1]=='a')
			{
				ans++;
				s[i]='b';
			}
			else if(s[i]=='b'&&s[i-1]=='b')
			{
				ans++;
				s[i]='a';
			}
		}
	}
	cout<<ans<<"\n";
	cout<<s<<"\n";
}
