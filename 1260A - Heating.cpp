#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int a,b;
		cin>>a>>b;
		int c=b%a;
		b/=a;a-=c;
		long long ans=b*b*a;
		b++;
		ans+=b*b*c;
		cout<<ans<<"\n";
	}
}
