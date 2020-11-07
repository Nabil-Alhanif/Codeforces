#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
		int tmp=(n+3)/4;
		for (int i=0;i<n-tmp;i++)
			cout<<9;
		for (int i=0;i<tmp;i++)
			cout<<8;
		cout<<"\n";
	}
}
