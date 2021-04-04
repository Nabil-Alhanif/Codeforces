#include <bits/stdc++.h>
using namespace std;
int main() {
	int m, n,ans=0;
	cin>>m>>n;
	int ar[m];
	for (int i = 0; i < m; i++) {
		cin>>ar[i];
	}
	sort(ar,ar+m);
	for (int i = 0; i < n && ar[i]<0; i++) {
		ans-=ar[i];
	}
	cout<<ans<<"\n";
}
