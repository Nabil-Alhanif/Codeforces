#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int j = 0,k=2;
	for (int i = 1; n>=i; i+=k,j++,k++) {
		n-=i;
	}
	cout << j << "\n";
}
