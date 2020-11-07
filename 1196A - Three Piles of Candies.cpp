#include <bits/stdc++.h>
using namespace std;

long long count() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long total = a+b+c;
	long long get = total/2;
	return get;
}

int main() {
	int q;
	cin >> q;
	long long ar[q] = {};
	for (int i = 0; i < q; i++) {
		ar[i] = count();
	}
	for(int j = 0; j < q; j++) {
		cout << ar[j] << endl;
	}
}
