#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		ll n,m,tmp=0,count=0;
		cin>>n>>m;
		for (tmp;tmp<=m*10;tmp+=m)
		{
			count+=tmp%10;
		}
		count*=n/(m*10);
		n%=(m*10);
		for (tmp=0;tmp<=n;tmp+=m)
		{
			count+=tmp%10;
		}
		cout<<count<<"\n";
	}
}
