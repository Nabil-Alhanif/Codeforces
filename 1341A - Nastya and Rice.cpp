#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int l=a-b,r=a+b;
		if (l*n<=c+d&&r*n>=c-d)
		{
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
}
