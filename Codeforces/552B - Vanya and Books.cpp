#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m=9,c=1,ans=0;
	cin>>n;
	while (n>=m)
	{
		n-=m;
		ans+=c*m;
		m*=10;
		c++;
	}
	ans+=c*n;
	cout<<ans<<"\n";
}
