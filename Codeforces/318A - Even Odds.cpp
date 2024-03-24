#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	ll n, k, o;
	cin >> n >> k;
	if (n%2==0) {
		o = n/2;
	} else o = n/2+1;
	if (k > o) {
		ll a = k-o;
		ll b = a*2;
		cout << b << endl;
	} else {
		ll b = k*2-1;
		cout << b << endl;
	}
}
