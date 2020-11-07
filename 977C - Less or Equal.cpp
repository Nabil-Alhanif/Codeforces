#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll ar[n];
	ll *pointer=&ar[0];
	for (pointer; pointer<=&ar[n-1]; pointer++) {
		cin>>*pointer;
	}
	sort(ar,ar+n);
	if (k==0&&ar[0]==1) {
		cout<<"-1\n";
		return 0;
	} else if (k==0&&ar[0]>1) {
		cout<<ar[0]-1<<"\n";
		return 0;
	}
	if (k<n) {
		if (ar[k-1]==ar[k]) {
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ar[k-1]<<"\n";
}
