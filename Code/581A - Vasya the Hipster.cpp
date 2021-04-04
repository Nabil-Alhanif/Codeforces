#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, b, d1, d2;
	cin >> r >> b;
	d1 = min(r, b);
	d2 = max(r, b)-min(r, b);
	d2/=2;
	cout << d1 << " " << d2 << endl;
}
