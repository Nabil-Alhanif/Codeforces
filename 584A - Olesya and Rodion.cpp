#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	if (n==1&&t==10) {
		cout << "-1\n";
	} else {
		if (t==10) {
			cout << "1" << string(n-1, '0');
		} else {
			cout << t << string(n-1,'0');
		}
	}
}
