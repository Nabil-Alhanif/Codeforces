#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,x,y,dif;
		cin>>n>>x>>y;
		for (int i=n-1;i>0;i--)
		{
			if ((y-x)%i==0)
			{
				//cout<<i<<"\n";
				dif=(y-x)/i;
				break;
			}
		}
		cout<<x<<" "<<y;
		//cout<<dif<<"\n";
		for (int i=x+dif;i<y&&n>2;i+=dif)
		{
			cout<<" "<<i;
			n--;
		}
		for (int i=x-dif;i>0&&n>2;i-=dif)
		{
			cout<<" "<<i;
			n--;
		}
		for (int i=y+dif;n>2;i+=dif)
		{
			cout<<" "<<i;
			n--;
		}
		cout<<"\n";
	}
}
