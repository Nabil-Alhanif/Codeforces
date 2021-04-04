#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin>>n;
	ll teacher[n],student[n],dif[n];
	for (int i = 0; i < n; i++) {
		cin>>teacher[i];
	}
	for (int i = 0; i < n; i++) {
		cin>>student[i];
		dif[i]=teacher[i]-student[i];
	}
	sort(dif,dif+n);
	ll l=0, r=n-1;
	ll ans=0;
	while (l<r) {
		if(dif[l]+dif[r]>0) {
			ans+=r-l;
			r--;
		} else l++;
	}
	cout<<ans<<"\n";
}
