#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	int size = n.size();
	for (int i = 0; i < size-2; i++) {
		if (n[i]=='W'&&n[i+1]=='U'&&n[i+2]=='B') {
			n[i]=' ';
			n[i+1]='0';
			n[i+2]='0';
		}
	}
	for (int i =0; i < size; i++) {
		if (n[i]!= '0')cout << n[i];
	}
}
