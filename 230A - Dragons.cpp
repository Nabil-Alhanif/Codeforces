#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int main() {
	bool lanjut=true;
	int s, n;
	cin >> s >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (s<=v[i].first) {
			lanjut=false;
			break;
		} else {
			s+=v[i].second;
		}
	}
	if (lanjut) cout << "YES\n";
	else cout << "NO\n";
}
