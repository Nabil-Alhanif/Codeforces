#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, book = 0;
	cin >> n >> k;
	int r, g, b;
	r = n*2;
	g = n*5;
	b = n*8;
	if (r % k == 0) {
		book += r/k;
	} else {
		book += r/k+1;
	}
	if (g % k == 0) {
		book += g/k;
	} else {
		book += g/k+1;
	}
	if (b % k == 0) {
		book += b/k;
	} else {
		book += b/k+1;
	}
	cout << book << endl;
}
