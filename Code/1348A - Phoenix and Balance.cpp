#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		n/=2;
		n=pow(2,n+1);
		cout<<n-2<<"\n";
	}
}
