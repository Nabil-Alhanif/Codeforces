#include <bits/stdc++.h>
using namespace std;
int perfect[10001];
int sum (int n) {
	int total=0;
	while (n>0) {
		total+=n%10;
		n/=10;
	}
	return total;
}
int main() {
	int i = 0;
	int count = 1;
	while (i<10000) {
		if (sum(count)==10) {
			i++;
			perfect[i]=count;
		}
		count++;
	}
	int test;
	cin >> test;
	cout << perfect[test] << "\n";
}
