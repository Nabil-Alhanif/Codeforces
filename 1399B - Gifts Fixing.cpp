#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while (t--)
	{
		long long n;
		cin>>n;
		long long a[n],b[n],am=LLONG_MAX,bm=LLONG_MAX,ans=0;
		for (long long i=0;i<n;i++)
		{
			cin>>a[i];
			am=min(a[i],am);
		}
		for (long long i=0;i<n;i++)
		{
			cin>>b[i];
			bm=min(b[i],bm);
		}
		for (long long i=0;i<n;i++)
		{
			ans+=max(a[i]-am,b[i]-bm);
		}
		cout<<ans<<"\n";
	}
}
