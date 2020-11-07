#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin >> n;
	if (n==0) cout << 0 << endl;
	else {
		if (n%2==0) {
			ll a = n/2;
			cout << a << endl;
		} else {
			ll a = n/2+1;
			a*=-1;
			cout << a << endl;
		}
	}
}
