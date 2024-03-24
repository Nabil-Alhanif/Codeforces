#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	map<int,int>used,m;
	map<int,vector<int> >v;
	int n,n2;
	cin>>n>>n2;
	while (n2--)
	{
		int p1,p2;
		cin>>p1>>p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	pair<int,int> ar[n];
	int ar2[n+1]={0};
	for (int i=0;i<n;i++)
	{
		int iter;
		cin>>iter;
		ar[i]={iter,i+1};
		m[i+1]=iter;
	}
	sort(ar,ar+n);
	for (auto&p:ar)
	{
		map<int,bool>dif;
		for (auto&tmp:v[p.second])
		{
			if (p.first==m[tmp])
			{
				cout<<"-1\n";
				return 0;
			}
			if (m[tmp]<p.first&&m[tmp]!=0)
			{
				if (!dif[m[tmp]])dif[m[tmp]]=1;
			}
		}
		if (dif.size()!=p.first-1)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(auto&i:ar)cout<<i.second<<" ";
	cout<<"\n";
}
