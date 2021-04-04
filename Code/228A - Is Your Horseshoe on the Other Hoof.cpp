#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> m;
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	cout << 4-m.size() << "\n";
}
