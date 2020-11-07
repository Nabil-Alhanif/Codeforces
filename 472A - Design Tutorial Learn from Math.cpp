#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	if (n%2==0) {
		cout << n-8 << " " << 8 << "\n";
	} else {
		cout << n-9 << " " << 9 << "\n";
	}
}
