#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
1
165 7
2 18
10 8
*/
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll p,f,a,b,s,w,ans=0;
		cin>>p>>f>>a>>b>>s>>w;
		for (int i=0;i<=a;i++)
		{
			ll tmp=0;
			if (p>=i*s)
			{
				tmp+=i;
				ll p2=p-i*s;
				//cout<<p2<<" p2 ";
				ll tmp2=p2/w;
				tmp2=min(tmp2,b);
				ll b2=b-tmp2;
				tmp+=tmp2;
				if (s<=w)
				{
					tmp2=f/s;
					//cout<<f<<" fj ";
					tmp2=min(tmp2,a-i);
					tmp+=tmp2;
					ll f2=f-tmp2*s;
					//cout<<f2<<" f2 ";
					tmp2=f2/w;
					tmp2=min(tmp2,b2);
					tmp+=tmp2;
				}
				else
				{
					tmp2=f/w;
					//cout<<f<<" fn ";
					tmp2=min(tmp2,b2);
					tmp+=tmp2;
					ll f2=f-tmp2*w;
					//cout<<f2<<" f2 ";
					tmp2=f2/s;
					tmp2=min(tmp2,a-i);
					tmp+=tmp2;
				}
				//cout<<"\n";
				ans=max(ans,tmp);
			}
			else continue;
		}
		cout<<ans<<"\n";
	}
}
