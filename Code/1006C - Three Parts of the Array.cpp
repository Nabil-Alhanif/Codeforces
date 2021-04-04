#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n,ans=0;
	cin>>n;
	ll ar[n],pref[n]={0},suff[n]={0};
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	pref[0]=ar[0];
	suff[0]=ar[n-1];
	for (int i = 1; i < n; i++) {
		pref[i]=pref[i-1]+ar[i];
		suff[i]=suff[i-1]+ar[n-i-1];
	}
	/*
	for (int i=0; i < n; i++) {
		cout<<suff[i]<<" ";
	}cout<<"\n";
	*/
	for (int i = 0; i < n; i++) {
		if(binary_search(suff,suff+n-i-1,pref[i])) ans=pref[i];
	}
	cout<<ans<<"\n";
}
