#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll letter[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	inline void operator+=(const node&l)
	{
		for (int i=0;i<26;i++)
		{
			this->letter[i]+=l.letter[i];
		}
	}
	
	inline node operator+(const node&l)
	{
		node ret;
		for (int i=0;i<26;i++)
		{
			ret.letter[i]=this->letter[i]+l.letter[i];
		}
		return ret;
	}
	
	inline node operator-(const node&l)
	{
		node ret;
		for (int i=0;i<26;i++)
		{
			ret.letter[i]=this->letter[i]-l.letter[i];
		}
		return ret;
	}
};

int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
	
		ll n,m;
		cin>>n>>m;
		node ar[n+1]; int p[m];
		string s;
		cin>>s;
		for (int i=0;i<n;i++)
		{
			ar[i+1].letter[s[i]-'a']++;
			ar[i+1]+=ar[i];
		}
		/*
		for (int i=0;i<26;i++)
		{
			cout<<ar[n].letter[i]<<" ";
		}
		*/
		node ans;
		for (int i=0;i<m;i++)
		{
			ll tmp;
			cin>>tmp;
			ans+=ar[tmp];
		}
		ans+=ar[n];
		for (int i=0;i<26;i++)
		{
			cout<<ans.letter[i]<<" ";
		}
		cout<<"\n";
	}
}
