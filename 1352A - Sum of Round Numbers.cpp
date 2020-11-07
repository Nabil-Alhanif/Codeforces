#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		vector<string> ans;
		string s;
		cin>>s;
		ll n=s.size();
		for (int i=0;i<n;i++)
		{
			if (s[i]!='0')
			{
				ans.push_back({s[i]+(string(n-i-1,'0'))});
			}
		}
		cout<<ans.size()<<"\n";
		for (auto i:ans)cout<<i<<" ";
		cout <<"\n";
	}
}
