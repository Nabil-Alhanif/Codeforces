#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,int> m;
	int n;
	cin>>n;
	int ar[n+2];
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		m[ar[i]]=i;
	}
	ar[m[n]-1]=0;
	ar[m[n]+1]=0;
	for (int i=n-1;i>=0;i--)
	{
		if (ar[m[i]]!=0) return cout<<"NO\n",0;
		ar[m[i]-1]=0;
		ar[m[i]+1]=0;
	}
	cout<<"YES\n";
}
