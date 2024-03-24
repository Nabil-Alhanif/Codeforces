#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll ans=0, a, b;
	cin>>a>>b;
	while (a!=0&&b!=0)
	{
		if(a<b)swap(a, b);
		ans+=a/b;
		a%=b;
	}
	cout<<ans<<"\n";
}
