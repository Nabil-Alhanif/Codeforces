#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, total=0;
	bool x = true;
	cin >> n;
	string s;
	cin >> s;
	int temp=0;
	for (int i = 0; i < n; i++) {
		if (s[i]!='x') {
			x = false;
			int temp2 = temp-2;
			if (temp2 > 0) total+=temp2;
			temp = 0;
		}
		if (s[i]=='x') {
			x=true;
			temp++;
		}
		if (i==n-1) {
			int temp3 = temp-2;
			if (temp3>0)total += temp3;
		}
	}
	cout << total << endl;
}
