#include <bits/stdc++.h>

using namespace std;

int main() {
	string str1;
	int y = 0, n;
	cin >> str1;
	int size = str1.size();
	for (int i = 0; i < size; i++) {
		if (str1[i] == 'a') y += 1;
	}
	n = size - y;
	if (y <= n) {
		int x = n-y;
		n -= x+1;
		size = n+y;
	}
	cout << size << endl;
}
