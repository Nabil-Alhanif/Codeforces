#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int size = s.length();
	map <char, int> m;
	for (int i = 0; i < size; i++) {
		if (s[i]>='a'&&s[i]<='z') {
			m[s[i]]++;
		}
	}
	cout << m.size() << "\n";
}
