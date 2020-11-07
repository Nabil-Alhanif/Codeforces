#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct hasil
{
	ll score;
	ll penalty;
	
	hasil(ll b, ll c)
	{
		this->score=b;
		this->penalty=c;
	}
	
	bool operator< (const hasil& banding) const
	{
		if (score==banding.score)
		{
			return (penalty<banding.penalty);
		}
		return (score>banding.score);
	}
};

int main()
{
	ll n,k;
	cin>>n>>k;
	map<hasil,ll> m;
	vector<hasil> v;
	for (int i=0;i<n;i++)
	{
		ll s, p;
		cin>>s>>p;
		v.push_back(hasil(s,p));
		m[hasil(s,p)]++;
	}
	sort(v.begin(),v.end());
	/*
	for (auto i:v)
		cout<<i.score<<" "<<i.penalty<<"\n";
	*/
	cout<<m[v[k-1]]<<"\n";
}
