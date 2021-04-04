#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,k;
		cin>>n>>k;
		if (n>=k)
		{
			n-=k;
			if (n%2)cout<<"1\n";
			else cout<<"0\n";
			continue;
		}
		cout<<k-n<<"\n";
	}
}
