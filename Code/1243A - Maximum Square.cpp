#include <bits/stdc++.h>
using namespace std;
map <int, int> m;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, maks=0;;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x]++;
			if (maks<x) {
				maks = x;
			}
		}
		int pos = 0;
		for (int i = 0; i <= maks; i++) {
			int p = 0;
			for (int j = i; j <= maks; j++) {
				p+=m[j];
			}
			if (i <= p) {
				pos =  i;
			}
		}
		cout << pos << "\n";
		m.clear();
	}
}
