#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int ans=INT_MAX,t=0;
	int n;
	cin>>n;
	int ar[n];
	for (int i=0;i<n;i++)
		cin>>ar[i];
	sort(ar,ar+n);
	for (int i=ar[0];i<=ar[n-1];i++)
	{
		int tmp=0;
		for (int j=0;j<n;j++)
		{
			if (ar[j]!=i)
			{
				tmp+=max(ar[j],i)-min(ar[j],i)-1;
			}
		}
		if (ans>tmp)
		{
			ans=tmp;
			t=i;
		}
		//cout<<tmp<<"\n";
	}
	cout<<t<<" "<<ans<<"\n";
}
