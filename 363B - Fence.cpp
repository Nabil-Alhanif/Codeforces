#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,k,maxHigh=LLONG_MAX,pos=1;
	cin>>n>>k;
	ll fence[n+1];
	fence[0]=0;
	for (int i = 1; i <= n; i++) {
		cin>>fence[i];
		fence[i]+=fence[i-1];
	}
	for (int i = 1; i <= n-k+1;i++) {
		ll tmp=fence[i+k-1]-fence[i-1];
		if(tmp<maxHigh) {
			maxHigh=tmp;
			pos=i;
		}
	}
	cout<<pos<<"\n";
}
