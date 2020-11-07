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
		int ar[n],dpa[n],dpb[n];
		for (int i=0;i<n;i++)
			cin>>ar[i];
		dpa[0]=ar[0];dpb[n-1]=ar[n-1];
		int l=-1,r=n,a=0,b=0,la=0,lb=0,ans=0;
		while (r>l)
		{
			la=0;
			for (int i=l+1;i<r;)
			{
				la+=ar[i];
				l++;
				i++;
				if (la>lb)break;
			}
			ans++;
			a+=la;
			if (l+1==r) break;
			lb=0;
			for (int i=r-1;i>l;)
			{
				lb+=ar[i];
				r--;
				i--;
				if(lb>la)break;
			}
			b+=lb;
			ans++;
			if (l+1==r)break;
		}
		cout<<ans<<" "<<a<<" "<<b<<"\n";
	}
}
