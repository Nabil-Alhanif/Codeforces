#include <bits/stdc++.h>
using namespace std;

long long count(long long x, long long a) {
	if (x%a == 0) {
		return x/a;
	} else {
		return x/a + 1;
	}
}

int main() {
	long long n, m, a;
	cin >> n >> m >> a;
	long long jawaban = count(n, a)*count(m,a);
	cout << jawaban << endl;
	return 0;
}
