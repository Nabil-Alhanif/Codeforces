#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, total = 0;
	cin >> n;
	while (n > 0) {
		if (n >= 100) {
			total += n/100;
			n = n%100;
		}
		if (n >= 20 && n < 100) {
			total += n/20;
			n = n%20;
		}
		if (n >= 10 && n < 20) {
			total += n/10;
			n = n%10;
		}
		if (n >= 5 && n < 10) {
			total += n/5;
			n = n%5;
		}
		else {
			total += n;
			n = 0;
		}
	}
	cout << total << endl;
}
