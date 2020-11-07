#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int size = s.length();
		if (s[size-1]=='o') {
			cout << "FILIPINO\n";
		} else if (s[size-1]=='u') {
			cout << "JAPANESE\n";
		} else {
			cout << "KOREAN\n";
		}
	}
}
