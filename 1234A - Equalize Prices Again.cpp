#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int q;
	cin>>q;
	while(q--) {
		int n;
		cin>>n;
		ll sum=0;
		for (int i=0;i<n;i++) {
			ll tmp;
			cin>>tmp;
			sum+=tmp;
		}
		cout<<(sum%n==0?sum/n:sum/n+1)<<"\n";
	}
}
