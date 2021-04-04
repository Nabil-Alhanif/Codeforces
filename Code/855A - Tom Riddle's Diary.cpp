#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string name[n];
	for (int i = 0; i < n; i++) {
		cin >> name[i];
	}
	for (int i = 0; i < n;i++) {
		bool p = false;
		for (int j = 0; j < i; j++) {
			if (name[i]==name[j]) p = true;
		}
		if (p) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
