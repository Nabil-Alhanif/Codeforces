#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll c2=0,t=0;
	while (n>0)
	{
		t++;
		c2+=pow(2,(n%10==7?t:t-1));
		n/=10;
	}
	cout<<c2<<"\n";
}
