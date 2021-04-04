#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]==s[i+1]) {
			s.erase(i, 2);
			if(i==0)i--;
			else i-=2;
		}
	}
	cout << s << endl;
}
