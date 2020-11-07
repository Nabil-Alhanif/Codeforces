#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--) {
		ll a, b, c,ans=0;
		cin >> a>> b >> c;
		if (a>(b+c)) {
			cout << c+1 << "\n";
		} else if (a+c<=b) {
			cout << "0\n";
			continue;
		} else if ((a+c-b)%2==0) {
			cout << (a+c-b)/2 << "\n";
		} else if ((a+c-b)%2==1) {
			cout << (a+c-b+1)/2 << "\n";
		}
	}
}
