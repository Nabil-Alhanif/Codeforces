#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,c=0,ans=0;;
	cin>>n>>d;
	for (int i=0;i<d;i++)
	{
		string s;
		cin>>s;
		if (s.find("0")==string::npos)
		{
			ans=max(ans,c);
			c=0;
		} else c++;
		ans=max(ans,c);
	}
	cout<<ans<<"\n";
}
