#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	map<int,vector<int> > road,roadt;
	map<int,bool>isVisit;
	map<int,int>dist;
	for (int i=0;i<m;i++)
	{
		int p1,p2;
		cin>>p1>>p2;
		roadt[p1].push_back(p2);
		road[p2].push_back(p1);
	}
	int k;
	cin>>k;
	int path[k];
	for (int i=0;i<k;i++)
	{
		cin>>path[i];
	}
	queue<int>q;
	q.push(path[k-1]);
	dist[path[k-1]]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for (auto way:road[p])
		{
			if(!dist[way])
			{
				dist[way]=dist[p]+1;
				q.push(way);
			}
		}
	}
	/*
	for (int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}cout<<"\n";
	*/
	long long mins=0,maks=0;
	for (int i=0;i<k-1;i++)
	{
		if (dist[path[i+1]]>=dist[path[i]])
		{
			mins++;
			continue;
		}
		bool ada=0;
		for (auto way:roadt[path[i]])
		{
			if (path[i+1]!=way&&dist[way]==dist[path[i+1]])ada=1;
		}
		if(ada)maks++;
		//if(tmp>0)tmp--;
	}
	cout<<mins<<" "<<mins+maks<<"\n";
}
