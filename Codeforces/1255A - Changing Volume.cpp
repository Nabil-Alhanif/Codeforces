#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b;
		cin>>a>>b;
		if (a==b)
		{
			cout<<"0\n";
			continue;
		}
		int dif=abs(a-b);
		int ans=0;
		if (dif>=5)
		{
			ans+=(dif/5);
			dif-=(dif/5)*5;
		}
		if (dif>=2)
		{
			ans+=dif/2;
			dif-=(dif/2)*2;
		}
		ans+=dif;
		cout<<ans<<"\n";
	}
}
