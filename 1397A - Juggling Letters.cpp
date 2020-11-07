#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		map<char,int>m;
		ll n;string s;bool b=1;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>s;
			for (auto i:s)m[i]++;
		}
		for (auto i:m)
		{
			if (i.second%n)
			{
				b=0;
				break;
			}
		}
		cout<<(b?"YES\n":"NO\n");
	}
}
