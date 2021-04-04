#include <bits/stdc++.h>
using namespace std;

int count() {
	int a, b, c, stone = 0;
	cin >> a >> b >> c;
	if (c>=2*b) {
		stone+=3*b;
		return stone;
	} else {
		stone+=(c/2)*3;
		b-=c/2;
	}
	if (b>=2*a) {
		stone+=3*a;
		return stone;
	} else{
		stone+=(b/2)*3;
		a-=(b/2);
	}
	return stone;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int tmp = count();
		cout << tmp << "\n";
	}
}
