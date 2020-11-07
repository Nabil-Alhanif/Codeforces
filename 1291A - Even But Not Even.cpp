#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> v;
		int n; string s;int count=0;
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			int c=s[i]-'0';
			if (c%2==1) {
				v.push_back(c);
				count++;
			}
		}
		bool can=false;
		for (int i = 0; i < count-1; i++) {
			if (v[i]%2==1&&v[i+1]%2==1) {
				cout << v[i]<<v[i+1]<<"\n";
				can=true;
				break;
			}
		}
		if (!can)cout << -1 << "\n";
	}
}
