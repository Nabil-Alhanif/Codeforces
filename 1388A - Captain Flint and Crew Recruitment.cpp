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
		if (n<=30)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		if (n==36)cout<<"6 10 15 5\n";
		else if (n==40)cout<<"6 10 15 9\n";
		else if (n==44)cout<<"6 10 15 13\n";
		else cout<<"6 10 14 "<<n-30<<"\n";
	}
}
