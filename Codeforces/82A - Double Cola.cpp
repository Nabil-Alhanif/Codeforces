#include <bits/stdc++.h>
using namespace std;
string character[5]={"Sheldon\n", "Leonard\n", "Penny\n", "Rajesh\n", "Howard\n"};
int main() {
	int n;
	cin >> n;
	int t1=1;
	while (t1*5<n) {
		n-=t1*5;
		t1*=2;
	}
	cout << character[(n-1)/t1];
}
