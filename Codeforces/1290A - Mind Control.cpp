#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while (t--) {
		int n, m, k,ans=0;;
		cin>>n>>m>>k;
		int ar[n];
		k=min(k,m-1);
		for (int i = 0; i < n; i++) {
			cin>>ar[i];
		}
		for (int i = 0; i <= k; i++) {
			int maks=INT_MAX;
			for (int j = 0; j < m-k; j++) {
				maks=min(maks,max(ar[i+j],ar[i+j+n-m]));
			}
			ans=max(ans,maks);
		}
		cout<<ans<<"\n";
	}
}
