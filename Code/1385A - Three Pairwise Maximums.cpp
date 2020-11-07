#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if (a==b&&a>=c)
			cout<<"YES\n"<<a<<" "<<c<<" "<<1<<"\n";
		else if (a==c&&a>=b)
			cout<<"YES\n"<<b<<" "<<a<<" "<<1<<"\n";
		else if (b==c&&b>=a)
			cout<<"YES\n"<<a<<" "<<1<<" "<<b<<"\n";
		else
			cout<<"NO\n";
	}
}
