#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, side = 0;
	cin >> n;
	string ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int j = 0; j < n; j++) {
		if (ar[j] == "Tetrahedron") side += 4;
		if (ar[j] == "Cube") side += 6;
		if (ar[j] == "Octahedron") side += 8;
		if (ar[j] == "Dodecahedron") side += 12;
		if (ar[j] == "Icosahedron") side += 20;
	}
	cout << side << endl;
}
