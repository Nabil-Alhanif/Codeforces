#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int n;
	cin >> s >> n;
	while (n--) {
		int l, r, m;
		cin >> l >> r >> m;
		string a = s.substr(l-1, r-l+1);
		string b = a;
		for (int i = 0; i < b.size(); i++) {
			int c = (i-m)%(r-l+1);
			if (c < 0) {
				c+=r-l+1;
			}
			b[i]=a[c];
		}
		s.erase(l-1, r-l+1);
		s.insert(l-1, b);
	}
	cout << s << endl;
}
