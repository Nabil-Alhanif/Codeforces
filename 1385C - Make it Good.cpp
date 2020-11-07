#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,del=0,last=0,lp=1;bool s=0;
		cin>>n;
		ll ar[n+1];ar[0]=0;
		for (int i=1;i<=n;i++)
		{
			cin>>ar[i];
			if (!s)
			{
				if (ar[i]<ar[i-1])s=1;
			}
			if (s)
			{
				if (ar[i]>ar[i-1])
				{
					s=0;
					del=lp-1;
				}
			}
			if (ar[i]!=last)
			{
				last=ar[i];
				lp=i;
				//cout<<ar[i]<<" "<<lp<<"\n";
			}
		}
		cout<<del<<"\n";
	}
}
