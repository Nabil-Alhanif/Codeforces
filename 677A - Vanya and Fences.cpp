#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, w=0;
	cin >> n >> h;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		if (ar[i]>h) w+=2;
		else w++;
	}
	cout << w << endl;
}
