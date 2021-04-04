#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, time = 0;
	cin >> a >> b;
	while (a <= b) {
		a = a*3;
		b = b*2;
		time += 1;
		if(a > b) break;
	}
	cout << time << endl;
}
