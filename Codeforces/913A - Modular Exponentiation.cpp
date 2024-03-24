#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n>26)cout << m << "\n";
	else {
		n = pow(2, n);
		cout << m%n << "\n";
	}
}
