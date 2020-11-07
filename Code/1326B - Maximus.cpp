#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll b[n], a[n];
	for (int i = 0; i < n; i++) {
		cin>>b[i];
	}
	ll maks=0;
	for (int i = 0; i < n; i++) {
		a[i]=maks;
		cout<<a[i]+b[i]<<" ";
		maks=max(maks, a[i]+b[i]);
	}
	cout<<"\n";
}
