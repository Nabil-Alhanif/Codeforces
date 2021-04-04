#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,ans=INT_MAX;
	cin>>a>>b;
	while (a--)
	{
		double x,y;
		cin>>x>>y;
		ans=min(ans,b*x/y);
	}
	cout<<setprecision(6)<<fixed<<ans<<"\n";
}
