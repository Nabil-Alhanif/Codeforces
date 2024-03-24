#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		ll n,k,ans=0;
		cin>>n>>k;
		while (n)
		{
			ans+=n%k;
			ans++;
			n/=k;
		}
		cout<<ans-1<<"\n";
	}
}
