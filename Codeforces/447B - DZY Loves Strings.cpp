#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;ll k,maks=0,ans=0;
	cin>>s>>k;
	ll score[26];
	for (int i=0;i<26;i++)
	{
		cin>>score[i];
		maks=max(maks,score[i]);
	}
	int i=0;
	for (i;i<s.size();i++)
	{
		ans+=score[s[i]-'a']*(i+1);
	}
	for (i+=1;i-s.size()<=k;i++)
	{
		//cout<<i<<"\n";
		ans+=i*maks;
	}
	cout<<ans<<"\n";
}
