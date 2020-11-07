#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,xa,ya;
	bool c1=0,c2=0;
	cin>>n>>xa>>ya;
	map<double,int>m;
	while (n--)
	{
		double x,y;
		cin>>x>>y;
		x-=xa;
		y-=ya;
		if (y&&x)
		{
			double grad=y/x;
			m[grad]++;
		}
		if (y==0)c1=1;
		if (x==0)c2=1;
	}
	cout<<m.size()+(c1?1:0)+(c2?1:0)<<"\n";
}
