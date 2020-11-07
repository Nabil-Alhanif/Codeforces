#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > m;
int main() {
	int t;
	cin >> t;
	while (t--) {
		bool ada = false;
		int n;
		cin >> n;
		int pos=n;
		int x;
		for (int i= 0; i < n; i++) {
			cin >> x;
			if (m[x].first>=1) {
				pos = min(pos, i-m[x].second);
				ada = true;
			}
			m[x] = make_pair(m[x].first+1, i);
		}
		if (!ada) pos = -1;
		else if (ada) pos++;
		cout << pos << "\n";
		m.clear();
	}
}
