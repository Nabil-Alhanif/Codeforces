#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, dis=0;
	cin >> a >> b >> c;
	int d = a+b;
	if (d<=c) {
		dis=d*2;
	} else if (d>c&&d<=c*2) {
		dis=d+c;
	} else {
		dis=c*2+min(a, b)*2;
	}
	cout << dis << endl;
}
