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
		int ar[n];
		for (int i=0;i<n;i++)cin>>ar[i];
		if (ar[0]+ar[1]<=ar[n-1])cout<<"1 2 "<<n<<"\n";
		else cout<<"-1\n";
	}
}
