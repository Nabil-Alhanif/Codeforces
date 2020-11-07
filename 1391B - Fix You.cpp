#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,m,ans=0;
		cin>>n>>m;
		char ar[n][m];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				cin>>ar[i][j];
		for (int i=0;i<m-1;i++)
			if (ar[n-1][i]!='R')
				ans++;
		for (int i=0;i<n-1;i++)
			if (ar[i][m-1]=='R')
				ans++;
		cout<<ans<<"\n";
	}
}
