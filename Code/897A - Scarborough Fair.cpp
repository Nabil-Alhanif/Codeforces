#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	while (m--) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		string t = s.substr(l-1, r-l+1);
		for (int i = 0; i < r-l+1; i++) {
			if (t[i]==c1) t[i]=c2;
		}
		s.erase(l-1, r-l+1);
		s.insert(l-1, t);
	}
	cout << s << endl;
}
