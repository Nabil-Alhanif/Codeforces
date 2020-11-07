#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;string s;
		cin>>n>>s;
		int ar[n*2-1];
		for (int i=0;i<n*2-1;i++)
		{
			ar[i]=s[i]-'0';
		}
		for (int i=0,j=0;i<n;i++,j++)
		{
			cout<<ar[i+j];
		}cout<<"\n";
	}
}
