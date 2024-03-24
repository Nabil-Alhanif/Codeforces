#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		if (n==1)
		{
			cout<<"YES\n";
			continue;
		}
		sort(ar,ar+n);
		bool b=1;
		for (int i=1;i<n;i++)
		{
			if (ar[i]-ar[i-1]>1)
			{
				b=0;
				break;
			}
		}
		cout<<(b?"YES\n":"NO\n");
	}
}
