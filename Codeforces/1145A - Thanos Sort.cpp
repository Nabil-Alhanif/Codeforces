#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n,ans=1;
	cin>>n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	for (int i = 2; i<=n; i*=2) {
		for (int j=0; j<n; j+=i) {
			bool sorted=1;
			for (int k=j+1; k<j+i; k++) {
				if(ar[k]<ar[k-1]) {
					sorted=0;
					break;
				}
			}
			if(sorted)ans=max(ans,i);
		}
	}
	cout<<ans<<"\n";
}
