#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		ll a,b=0,c=0;
		cin>>a;
		while(!(a%3))
		{
			b++;
			a/=3;
		}
		c=log2(a);
		if (pow(2,c)==a)
		{
			if (b>=c)cout<<b+b-c<<"\n";
			else cout<<"-1\n";
		}
		else
		{
			cout<<"-1\n";
		}
	}
}
