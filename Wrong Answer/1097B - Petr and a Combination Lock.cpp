#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ar[n+1];
	ar[0]=0;
	for (int i=1;i<=n;i++)cin>>ar[i];
	sort(ar,ar+n);
	for (int i=2;i<=n;i++)ar[i]+=ar[i-1];
	for (int i=0;i<=n;i++)
	{
		int tmp=ar[n]-ar[i];
		//cout<<ar[i]<<" "<<tmp<<"\n";
		if (ar[i]==tmp)return cout<<"YES\n",0;
		if (tmp-ar[i]==360)return cout<<"YES\n",0;
		if (ar[i]-tmp==360)return cout<<"YES\n",0;
	}
	cout<<"NO\n";
}
