#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll ar[n],ans=0,pos=0;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	for (int i=0;i<n;i++)
	{
		ll tmp=ar[i];
		ll lim=ar[i];
		for (int j=i-1;j>=0;j--)
		{
			lim=min(lim,ar[j]);
			tmp+=lim;
		}
		lim=ar[i];
		for (int j=i+1;j<n;j++)
		{
			lim=min(lim,ar[j]);
			tmp+=lim;
		}
		if(tmp>ans)
		{
			pos=i;
			ans=tmp;
		}
	}
	ll lim=ar[pos];
	for (int i=pos-1;i>=0;i--)
	{
		lim=min(lim,ar[i]);
		ar[i]=lim;
	}
	for (int i=0;i<pos;i++)cout<<ar[i]<<" ";
	cout<<ar[pos];
	lim=ar[pos];
	for (int i=pos+1;i<n;i++)
	{
		lim=min(lim,ar[i]);
		cout<<" "<<lim;
	}cout<<"\n";
}
