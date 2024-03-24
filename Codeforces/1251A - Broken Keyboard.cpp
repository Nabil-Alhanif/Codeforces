#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = 0;
		while (i<s.size()) {
			while (s[i]==s[i+1]) {
				s.erase(i,2);
			}
			i++;
		}
		map<char, int> m;
		vector<char> v;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
			if (m[s[i]]==1)v.push_back(s[i]);
		}
		sort(v.begin(), v.end());
		for (auto i : v) cout << i;
		cout << "\n";
	}
}
