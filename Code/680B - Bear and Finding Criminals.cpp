#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a,i=0,ans=0;
	cin>>n>>a;
	a--;
	int ar[n];
	for (int i=0;i<n;i++)cin>>ar[i];
	for (i;a-i>=0&&a+i<n;i++)
	{
		if (ar[a-i]==1&&ar[a+i]==1)
		{
			if (i==0)ans++;
			else ans+=2;
		}
	}
	//cout<<i<<" "<<ans<<"\n";
	for (i;a-i>=0;i++)ans+=ar[a-i];
	//cout<<i<<" "<<ans<<"\n";
	for (i;a+i<n;i++)ans+=ar[a+i];
	//cout<<i<<" "<<ans<<"\n";
	//for (int i=0;i<n;i++){cout<<i<<" "<<ar[i]<<" ";}cout<<"\n";
	cout<<ans<<"\n";
}
