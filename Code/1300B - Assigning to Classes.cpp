#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int ar[n*2];
		for (int i=0;i<n+n;i++)cin>>ar[i];
		sort(ar,ar+n+n);
		int pLast=n-1;
		cout<<ar[pLast+1]-ar[pLast]<<"\n";
	}
}
