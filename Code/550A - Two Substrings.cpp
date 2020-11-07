#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int size = s.size();
	bool a=false, b=false;
	size_t found=s.find("AB");
	if (found!=string::npos) {
		size_t found2 = s.find("BA", found+2);
		if (found2!=string::npos) {
			cout << "YES\n";
			return 0;
		}
	}
	size_t found3 = s.find("BA");
	if (found3!=string::npos) {
		size_t found4 = s.find("AB", found3+2);
		if (found4!=string::npos) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
