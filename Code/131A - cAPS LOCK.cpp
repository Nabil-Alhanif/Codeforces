#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	bool big=false, small=false;
	cin >> s;
	if (s.size()==1) {
		char c = s[0];
		if (c >= 'A' && c <= 'Z') c = tolower(c);
		else c = toupper(c);
		cout << c << endl;
	}
	else {
		for (int i = 1; i < s.size(); i++) {
			char c = s[i];
			if (c >= 'A' && c <= 'Z') big = true;
			else small = true;
		}
		if (big&& not small) {
			for (int i = 0; i < s.size(); i++) {
				char c = s[i];
				if (c >= 'A' && c <= 'Z') c = tolower(c);
				else c = toupper(c);
				cout << c;
			}cout << endl;	
		}
		if (small) {
			cout << s << endl;
		}	
	}
	
}
