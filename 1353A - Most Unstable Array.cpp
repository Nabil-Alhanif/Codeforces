#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		ll n,m;
		cin>>n>>m;
		cout<<m*(min(n-1,2ll))<<"\n";
	}
}
