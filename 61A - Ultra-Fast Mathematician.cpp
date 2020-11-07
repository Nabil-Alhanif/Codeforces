#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s, s1;
	cin >> s >> s1;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (s[i]==s1[i])cout << "0";
		else cout << "1";
	} cout << "\n";
}
