#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, cells = 0;
	cin >> a >> b >> c;
	int d;
	d = a*2+(b-2)*2;
	cells = c*d;
	for (int i = 0; i < c; i++) {
		cells -= i*16;
	}
	cout << cells << endl;
}
