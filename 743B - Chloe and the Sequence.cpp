#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,k;
	cin>>n>>k;
	for (int i = n-1; i>=0; i--) {
		ll tmp=pow(2,i);
		//cout<<tmp<<" "<<k<<"\n";
		if(k>tmp) {
			k-=tmp;
		} else if (k==tmp) {
			cout<<i+1<<"\n";
			return 0;
		}
	}
}
