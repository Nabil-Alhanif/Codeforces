#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,k,ans=0,pos=1;
		cin>>n>>k;
		int ar[n+1],peak[n+1];
		ar[0]=0;ar[1]=0;
		peak[0]=0;peak[1]=0;peak[2]=0;
		for (int i=1;i<=n;i++)cin>>ar[i];
		for (int i=3;i<=n;i++)
		{
			peak[i]=peak[i-1];
			if (ar[i-1]>ar[i-2]&&ar[i-1]>ar[i])peak[i]++;
			if (i>=k)
			{
				if (peak[i]-peak[i-k+1]>ans)
				{
					ans=peak[i]-peak[i-k+1];
					pos=i-k+1;
				}
			}
		}/*
		for (int i=1;i<=n;i++)cout<<peak[i]<<" ";
		cout<<"\n";*/
		cout<<ans+1<<" "<<pos<<"\n";
	}
}
