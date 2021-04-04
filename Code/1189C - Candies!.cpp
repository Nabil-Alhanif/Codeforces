#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for (int i=0;i<n;i++)
		cin>>ar[i];
	int q;
	cin>>q;
	int pref[n+1];
	pref[0]=0;
	for (int i=1;i<=n;i++)
		pref[i]=pref[i-1]+ar[i-1];
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		int dif=pref[r]-pref[l-1];
		cout<<dif/10<<"\n";
	}
}
