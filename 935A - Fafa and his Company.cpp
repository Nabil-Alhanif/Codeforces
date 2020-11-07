#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, way = 0;
	cin >> n;
	for(int i =1; i < n; i++) {
		if (n%i==0) way += 1;
	}
	cout << way << endl;
}
