#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int angle;
		cin >> angle;
		int tmp = 180-angle;
		if (tmp!=0&&360%tmp==0) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}
