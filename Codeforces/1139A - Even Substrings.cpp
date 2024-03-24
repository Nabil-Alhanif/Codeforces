#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, total=0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i]%2 == 0) {
			total += i+1;
		}
	}
	cout << total << endl;
}
