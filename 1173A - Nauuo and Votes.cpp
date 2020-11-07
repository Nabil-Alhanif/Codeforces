#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c == 0){
		if (a > b) cout << "+" << endl;
		if (b > a) cout << "-" << endl;
		if (b == a) cout << "0" << endl;
	} else if (c != 0) {
		if (a > b+c) cout << "+" << endl;
		if (b > a+c) cout << "-" << endl;
		if (a > b) {
			if (a <= b+c) cout << "?" << endl;
		} else if(b > a) {
			if (b <= a+c) cout << "?" << endl; 
		} else cout << "?" << endl;
	}
}
