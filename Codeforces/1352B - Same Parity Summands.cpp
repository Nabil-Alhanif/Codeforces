#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,k;
		cin>>n>>k;
		if (n>=k)
		{
			if (!(n%2))
			{
				if (k*2<=n)
				{
					ll tmp=0;
					cout<<"YES\n";
					for (int i=0;i<k-1;i++)
					{
						cout<<"2 ";
						tmp+=2;
					}
					cout<<n-tmp<<"\n";
					continue;
				}
				if (!(k%2))
				{
					cout<<"YES\n";
					for (int i=0;i<k-1;i++)
					{
						cout<<"1 ";
					}
					cout<<n-k+1<<"\n";
					continue;
				}
			}
			else if (k%2)
			{
				cout<<"YES\n";
				for (int i=0;i<k-1;i++)
				{
					cout<<"1 ";
				}
				cout<<n-k+1<<"\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
}
