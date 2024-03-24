#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int a, b;
	string dec;
	dec = "EASY";
	cin >> a;
	int ar[a] = {};
	for (int i = 0; i < a; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < a; j++) {
		if (ar[j] == 1) {
			dec = "HARD";
		}
	}
	cout << dec << endl;
}
