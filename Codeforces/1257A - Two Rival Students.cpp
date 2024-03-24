#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long t;
	cin >> t;
	while (t--) {
		unsigned long long a, b, c, d;
		cin >> a >> b >> c >> d;
		unsigned long long n=1;
		n = max(c,d)-min(c,d);
		n+=b;
		cout << min(a-1, n) << "\n";
	}
}
