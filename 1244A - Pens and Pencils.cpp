#include <bits/stdc++.h>
using namespace std;

void count() {
	int pen, pencil, a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	if (a%c == 0) pen = a/c;
	if (a%c != 0) pen = floor(a/c) + 1;
	if (b%d == 0) pencil = b/d;
	if (b%d != 0) pencil = floor(b/d)+1;
	if (pen + pencil <= k) cout << pen << " " << pencil << endl;
	else cout << -1 << endl;
}

int main() {
	int t;
	cin >> t;
	int ar[t];
	for (int i = 0; i < t; i++) {
		count();
	}
}
