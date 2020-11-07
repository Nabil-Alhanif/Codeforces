#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	sort(ar,ar+n,greater<int>());
	int ans=0;
	for (int i=0; i<n;i++) {
		m-=ar[i];
		ans++;
		if (m<=0) {
			break;
		}
	}
	cout<<ans<<"\n";
}
