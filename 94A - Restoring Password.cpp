#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ar[10];
	for (int i = 0; i < 10; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < 80; j+=10) {
		for (int i = 0; i < 10; i++) {
			if (s.substr(j, 10)==ar[i]) cout << i;
		}
	}
}
