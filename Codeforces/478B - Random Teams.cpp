#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll getSum(ll x) {
	x--;
	float ret = (1+x)*(float)x/2;
	return (ll)ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	ll tmp=n/m,tmp2=n%m;
	ll mins = 0;
	for(int i = 0; i < tmp2; i++) {
		mins+=getSum(tmp+1);
	}
	for (int i = 0; i < m-tmp2; i++) {
		mins+=getSum(tmp);
	}
	ll maks=getSum(n-m+1);
	cout<<mins<<" "<<maks<<"\n";
}
