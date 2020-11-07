#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll pref[n+2],suff[n+2],ar[n+2],pSum[n+2],sSum[n+2];
	ar[0]=ar[n+1]=0;
	for (int i=1;i<=n;i++)cin>>ar[i];
	pref[0]=0;
	pref[1]=0;
	pSum[0]=sSum[n+1]=0;
	pSum[1]=ar[1];
	sSum[n]=ar[n];
	for (int i=2;i<=n;i++)
	{
		ll j=i-1;
		while(j>0&&ar[j]>=ar[i])
		{
			j=pref[j];
		}
		pref[i]=j;
		pSum[i]=pSum[j]+(i-j)*ar[i];
	}
	//cout<<"as\n";
	suff[n]=n+1;
	for (int i=n-1;i>=1;i--)
	{
		ll j=i+1;
		while (ar[j]>=ar[i]&&j<=n)
		{
			j=suff[j];
		}
		suff[i]=j;
		sSum[i]=sSum[j]+(j-i)*ar[i];
	}/*
	for (int i=1;i<=n;i++)
	{
		cout<<pref[i]<<" ";
	}cout<<"\n";
	for (int i=1;i<=n;i++)
	{
		cout<<suff[i]<<" ";
	}cout<<"\n";
	for (int i=1;i<=n;i++)
	{
		cout<<pSum[i]<<" ";
	}cout<<"\n";
	for (int i=1;i<=n;i++)
	{
		cout<<sSum[i]<<" ";
	}cout<<"\n";*/
	ll ans=0,pos=1;
	for (int i=1;i<=n;i++)
	{
		if (pSum[i]+sSum[i]-ar[i]>ans)
		{
			ans=pSum[i]+sSum[i]-ar[i];
			pos=i;
		}
	}
	ll last=ar[pos];
	for (int i=pos-1;i>=1;i--)
	{
		last=min(last,ar[i]);
		ar[i]=last;
	}
	last=ar[pos];
	for (int i=pos+1;i<=n;i++)
	{
		last=min(last,ar[i]);
		ar[i]=last;
	}
	for (int i=1;i<=n;i++)cout<<ar[i]<<" ";cout<<"\n";
}
