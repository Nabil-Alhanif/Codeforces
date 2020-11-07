#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int longPath=0, endPath=0, last=0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp>=last)endPath++;
		else {
			endPath=1;
		}
		longPath=max(longPath, endPath);
		last=tmp;
	}
	cout << longPath << "\n";
}
