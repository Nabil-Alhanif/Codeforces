#include <bits/stdc++.h>
using namespace std;

int main() {
	double n, R, r;
	cin >> n >> R >> r;
	if (r>R/2&&n<=1&&r<=R) {
		cout << "YES\n";
		return 0;
	} else if (r==R/2&&n<=2) {
		cout << "YES\n";
		return 0;
	}
	double tmp = r/(R-r);
	tmp = n*asin(tmp);
	if (tmp<=3.1415927) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}
