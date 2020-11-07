#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int size = s.length();
	int count=0;
	for (int i = 0; i < size; i++) {
		if (s[i]>='a') count++;
	}
	if (size-count>count) {
		for (int i = 0; i < size; i++) {
			putchar(toupper(s[i]));
		}
	} else {
		for (int i = 0; i < size; i++) {
			putchar(tolower(s[i]));
		}
	}
	cout << "\n";
}
