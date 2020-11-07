#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,ans=0;
	cin>>n;
	ll ar[n];
	for (int i=0;i<n;i++) {
		cin>>ar[i];
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i++){
		if(ar[i]>ar[0]&&ar[i]<ar[n-1])ans++;
	}
	cout<<ans<<"\n";
}
