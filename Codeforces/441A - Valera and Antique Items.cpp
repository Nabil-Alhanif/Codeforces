#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	int n,v;
	vector<int>vect;
	cin>>n>>v;
	for (int i=1;i<=n;i++)
	{
		int mins=INT_MAX;
		int p;
		cin>>p;
		while (p--)
		{
			int cost;
			cin>>cost;
			mins=min(mins,cost);
		}
		if (mins<v)vect.push_back(i);
	}
	cout<<vect.size()<<"\n";
	for(auto i:vect)cout<<i<<" ";cout<<"\n";
}
