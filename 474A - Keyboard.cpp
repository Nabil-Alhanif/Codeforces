#include <bits/stdc++.h>
using namespace std;
int main() {
	string s="qwertyuiopasdfghjkl;zxcvbnm,./";
	char c; string t;
	cin >> c >> t;
	for (int i = 0; i < t.size(); i++) {
		size_t pos=s.find(t[i]);
		if (c=='L')cout << s[pos+1];
		else cout << s[pos-1];
	} cout << "\n";
}
