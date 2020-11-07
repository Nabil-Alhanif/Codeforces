#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,n;
		cin>>a>>b>>n;
		if(!(n%3))cout<<a;
		else if (n%3==1)cout<<b;
		else cout<<(a^b);
		cout<<"\n";
	}
}
