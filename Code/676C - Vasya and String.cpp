#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;string s;
	cin>>n>>k>>s;
	vector<int>v;
	vector<pair<int,int> >bPos;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='b')
		{
			int tmp=1;
			if (!bPos.empty())
			{
				tmp+=bPos.back().second;
			}
			bPos.push_back({i,tmp});
		}
	}
	/*
	v.push_back(1);
	for (int i=1;i<n;i++)
	{
		if (s[i]==s[i-1])v.back()+=1;
		else v.push_back(1);
	}
	int pos=0;
	for (auto i:v)
	{
		pos+=i;
		if (s[pos-1]=='b')
		{
			int tmp=i;
			if (bPos.size()>0)
			{
				tmp+=bPos.back().second;
			}
			bPos.push_back({pos,tmp});
		}
		cout<<i<<" ";
	}
	cout<<"\n";*/
	for (auto i:bPos)
	{
		cout<<i.first<<" "<<i.second<<"\n";
	}
}
