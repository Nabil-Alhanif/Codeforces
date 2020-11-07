#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int move=1;
	while (c>0) {
		if (move%2==1) {
			int fpb = __gcd(a, c);
			c-=fpb;
		} else {
			int fpb = __gcd(b,c);
			c-=fpb;
		} move++;
	}
	cout << move%2 << endl;
}
