#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll hole[n];
	for (int i=0;i<n;i++)
		cin>>hole[i];
	sort(hole+1,hole+n);
	for (int i=1;i<n;i++)
		hole[i]+=hole[i-1];
	for (int i=0;i<n;i++)
	{
		ll curFlow=hole[0]*a/hole[n-1-i];
		if (curFlow>=b)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
}
