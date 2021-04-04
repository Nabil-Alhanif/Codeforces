#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long ar[n][n];
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	long long a = ar[0][1]*ar[0][2]/ar[1][2];
	long long a2 = pow(a, 0.5);
	long long ar2[n];
	ar2[0]=a2;
	for (long long k = 1; k < n; k++) {
		ar2[k]= ar[0][k]/a2;
	}
	for (long long l = 0; l < n; l++) {
		cout << ar2[l] << " ";
	} cout << endl;
}
