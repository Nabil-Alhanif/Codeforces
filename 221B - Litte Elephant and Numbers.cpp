#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ar[10];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll x,ans=0;
	cin>>x;
	ll x2=x;
	while (x2>=10)
	{
		ar[x2%10]=1;
		x2/=10;
	}
	ar[x2]=1;
	/*
	for (int i=0;i<10;i++)
		cout<<ar[i]<<" ";
	*/
	for (int i=1;i*i<=x;i++)
	{
		if (x%i==0)
		{
			bool b1=0,b2=0;
			//cout<<i<<"\n";
			ll tmp=i;
			while (tmp>=10)
			{
				if(ar[tmp%10])
				{
					b1=1;
					ans++;
					break;
				}
				tmp/=10;
			}
			if (ar[tmp]&&!b1)ans++;
			tmp=x/i;
			//cout<<tmp<<"\n";
			if (tmp!=i)
			{
				while (tmp>=10)
				{
					if (ar[tmp%10])
					{
						b2=1;
						ans++;
						break;
					}
					tmp/=10;
				}
				if (ar[tmp]&&!b2)ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
