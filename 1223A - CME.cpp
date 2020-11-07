#include <bits/stdc++.h>
using namespace std;

int test(int n) {
	int add;
	if (n <= 4) {
		add = 4-n;
	}
	if (n > 4) {
		if (n%2 == 0) add = 0;
		if (n%2 == 1) add = 1;
	}
	return add;
}

int main() {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ar[i] = test(temp);
	}
	for (int j = 0; j < n; j++) {
		cout << ar[j] << endl;
	}
}
