#include <bits/stdc++.h>
using namespace std;

int main() {
	bool fine = false;
	int n;
	cin >> n;
	int a = 1234567, b = 123456, c = 1234;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			int k = (n-(a*i+b*j))/c;
			if (a*i+b*j+c*k==n and k>=0)fine = true;
		}
	}
	if (fine) cout << "YES\n";
	else cout << "NO\n";
}
