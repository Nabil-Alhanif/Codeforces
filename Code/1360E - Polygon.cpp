#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		char ar[n][n];
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)cin>>ar[i][j];
		}
		bool bisa=1;
		for (int i=0;i<n-1;i++)
		{
			for (int j=0;j<n-1;j++)
			{
				if (ar[i][j]=='1')
				{
					if (!(ar[i+1][j]=='1'||ar[i][j+1]=='1')) bisa=0;
				}
			}
		}
		cout<<(bisa?"YES\n":"NO\n");
	}
}
