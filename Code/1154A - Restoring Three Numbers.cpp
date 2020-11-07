#include <bits/stdc++.h>
using namespace std;

int main() {
	int ar[4];
	for(int i = 0; i < 4; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+4);
	long long most = ar[3]*2;
	int a, b, c;
	a = most - ar[2]*2;
	a = a/2;
	b = most - ar[1]*2;
	b = b/2;
	c = most - ar[0]*2;
	c = c/2;
	cout << a << " " << b << " " << c << endl;
}
