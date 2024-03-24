#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	char start='a';
	int move=0,size=s.length();
	for(int i = 0; i < size; i++) {
		int tmp = abs(start-s[i]);
		move+=min(tmp, 26-tmp);
		start=s[i];
	}
	cout << move <<"\n";
}
