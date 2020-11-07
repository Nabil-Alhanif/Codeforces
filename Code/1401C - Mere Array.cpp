#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,gcd=INT_MAX;
		cin>>n;
		int ar[n],ar2[n];
		for (int i=0;i<n;i++)
		{
			cin>>ar[i];
			gcd=min(gcd,ar[i]);
			ar2[i]=ar[i];
		}
		sort(ar,ar+n);
		for (int i=0;i<n;i++)
		{
			if(ar2[i]!=ar[i])
			{
				gcd=__gcd(gcd,ar2[i]);
			}
		}
		cout<<(gcd==ar[0]?"YES\n":"NO\n");
	}
}
