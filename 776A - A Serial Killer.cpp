#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n;
	cin >> n;
	cout << s1 << " " << s2 << endl;
	while (n--) {
		string s3, s4;
		cin >> s3 >> s4;
		if (s1 == s3) {
			s1 = s4;
		}
		if (s2 == s3) {
			s2 = s4;
		}
		cout << s1 << " " << s2 << endl;
	}
}
