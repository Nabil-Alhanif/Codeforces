#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]==s[i+1]) {
			s.erase(i, 2);
			i -= 2;
		}
		if (i < 0 && s.length()>=2) i = -1;
	}
	if (s.length()==0) cout << "Yes" << endl;
	else cout << "No" << endl;
}
