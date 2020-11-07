#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll m, n;
	cin >> n >> m;
	ll ar[n],ar2[n],ans[n];
	for (ll i= 0; i < n; i++) {
		cin >> ar[i];
	}
	sort (ar,ar+n);
	ar2[0]=ar[0];
	ans[0]=ar[0];
	for (ll i=1;i<n;i++)
	{
		ar2[i]=ar[i]+ar2[i-1];
		//cout<<ar2[i]<<" ";
		if(i>=m)
		{
			ar2[i]+=ar[i-m];
			//cout<<ar[i-m]<<" ";
		}
		//cout<<"\n";
		ans[i]=ar2[i];
		if (i>=m*2)ans[i]+=ans[i-m*2];
	}
	for (ll i=0;i<n;i++)cout<<ans[i]<<" ";cout<<"\n";
}
