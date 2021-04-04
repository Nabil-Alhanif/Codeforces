#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (s[i]=='H'||s[i]=='Q'||s[i]=='9') {
			cout << "YES\n";
			exit(0);
		}
	}
	cout << "NO\n";
}
