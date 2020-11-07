#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	int n,last,c=1,l=0;
	cin>>n;
	int ar[n];
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	last=ar[0];
	for (int i=1;i<n;i++)
	{
		if (last==ar[i])c++;
		else {
			last=ar[i];
			ans=max(ans,min(c,l));
			l=c;
			c=1;
		}
		if (i==n-1)
		{
			last=ar[i];
			ans=max(ans,min(c,l));
			l=c;
			c=1;
		}
		//cout<<i<<" "<<c<<"\n";
	}
	cout<<ans*2<<"\n";
}
