#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ar[5];
	bool can = false;
	for (int i = 0; i < 5; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < 2; j++) {
		for (int x = 0; x < 5; x++) {
			for(int k = 0; k < 2; k++) {
				if (s[j] == ar[x][k]) can = true;
			}
		}
	}
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl;
}
