#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b;
	a = n+1;
	b = n+2;
	int c, d, e;
	c = n%4;
	d = a%4;
	e = b%4;
	char c2, d2, e2;
	if (c == 1) c2 = 'A';
	if (c == 3) c2 = 'B';
	if (c == 2) c2 = 'C';
	if (c == 0) c2 = 'D';
	if (d == 1) d2 = 'A';
	if (d == 3) d2 = 'B';
	if (d == 2) d2 = 'C';
	if (d == 0) d2 = 'D';
	if (e == 1) e2 = 'A';
	if (e == 3) e2 = 'B';
	if (e == 2) e2 = 'C';
	if (e == 0) e2 = 'D';
	if (c2 < d2 && c2 < e2) {
		cout << 0 << " " << c2 << endl;
	}
	if (c2 > d2 && d2 < e2) {
		cout << 1 << " " << d2 << endl;
	}
	if (e2 < d2 && c2 > e2) {
		cout << 2 << " " << e2 << endl;
	}
}
