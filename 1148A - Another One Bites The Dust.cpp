#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,c,total=0;
	cin >> a >> b >> c;
	total += c*2;
	if (a == b) {
		total += a+b;
	}
	if (a<b) {
		total += a*2+1;
	}
	if (b<a) {
		total += b*2+1;
	}
	cout << total << endl;
}
