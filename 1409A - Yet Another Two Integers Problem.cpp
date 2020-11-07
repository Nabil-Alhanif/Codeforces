#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b;
		cin>>a>>b;
		double dif=abs(a-b);
		int ans=ceil(dif/10);
		cout<<ans<<"\n";
	}
}
