#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		map<int,int> m;
		int n;
		cin >> n;
		while (n--) {
			int tmp;
			cin >> tmp;
			m[tmp]++;
		}
		cout << m.size()<<"\n";
	}
}
