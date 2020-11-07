#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll time=0,n,ans=0;
	cin>>n;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	sort(ar,ar+n);
	for (int i = 0; i < n; i++) {
		if (time<=ar[i]) {
			time+=ar[i];
			ans++;
		}
	}
	cout<<ans<<"\n";
}
