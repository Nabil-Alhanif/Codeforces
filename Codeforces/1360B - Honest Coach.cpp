#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,ans=1000000;
		cin>>n;
		int ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		sort(ar,ar+n);
		for (int i=1;i<n;i++)
		{
			ans=min(ans,ar[i]-ar[i-1]);
		}
		cout<<ans<<"\n";
	}
}
