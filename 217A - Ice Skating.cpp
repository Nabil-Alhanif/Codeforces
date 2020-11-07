#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,vector<int> > x,y;
	int n,ans=0;
	cin>>n;
	while (n--)
	{
		int a,b;
		cin>>a>>b;
		if (x[a].empty()&&y[b].empty())ans++;
		x[a].push_back(b);
		y[b].push_back(a);
	}
	cout<<ans-1<<"\n";
}
