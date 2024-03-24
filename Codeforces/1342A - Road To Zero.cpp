#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		long long x,y,a,b,ans=0;
		cin>>x>>y>>a>>b;
		if (b<a*2)
		{
			if (x<0&&y<0)
			{
				ans+=b*min(abs(x),abs(y));
			} else if (x>=0&&y>=0)
			{
				ans+=b*min(x,y);
			}
			ans+=a*(max(abs(x),abs(y))-min(abs(x),abs(y)));
		} else {
			ans+=a*(abs(x)+abs(y));
		}
		cout<<ans<<"\n";
	}
}
