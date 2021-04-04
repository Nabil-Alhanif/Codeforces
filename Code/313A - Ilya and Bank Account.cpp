#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n<0) {
		int tmp = n/100;
		n=max(n/10, tmp*10+n%10);
	}
	cout << n << "\n";
}
