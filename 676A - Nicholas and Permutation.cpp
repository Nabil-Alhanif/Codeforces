#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,p1,p2;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp==1)p1=i;
		if (tmp==n)p2=i;
	}
	cout<<max(p2-1,max(p1-1,max(n-p1,n-p2)));
}
