#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	cin>>c;
	while (c--)
	{
		int n,s,t;
		cin>>n>>s>>t;
		int b=s+t-n;
		cout<<max(s,t)-b+1<<"\n";
	}
}
