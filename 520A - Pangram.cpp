#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int size;
	cin >> size;
	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < size; i++) {
		s[i]=tolower(s[i]);
		m[s[i]]++;
	}
	if (m.size()==26) cout << "YES\n";
	else cout << "NO\n";
}
