#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n, size=s.length();
	int ar[size]={0};
	for (int i = size-2; i >= 0; i--) {
		if (s[i]==s[i+1]) {
			ar[i]++;
		}
		ar[i]+=ar[i+1];
	}
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		cout << ar[l-1]-ar[r-1]<<"\n";
	}
}
