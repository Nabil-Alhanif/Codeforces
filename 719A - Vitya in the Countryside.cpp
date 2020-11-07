#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	if (n==1) {
		int tmp;
		cin>>tmp;
		if (tmp==15)cout<<"DOWN\n";
		else if (tmp==0)cout<<"UP\n";
		else cout<<"-1\n";
		return 0;
	}
	ll ar[n];
	for (int i=0;i<n;i++) {
		cin>>ar[i];
	}
	if (ar[n-1]==0)cout<<"UP\n";
	else if (ar[n-1]==15)cout<<"DOWN\n";
	else {
		if (ar[n-2]<ar[n-1])cout<<"UP\n";
		else cout<<"DOWN\n";
	}
}
