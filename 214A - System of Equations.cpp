#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, count = 0;
	cin >> n >> m;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if ((i*i+j)==n and (j*j+i)==m) {
				count++;
			}
		}
	}
	cout << count << "\n";
}
