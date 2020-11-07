#include <bits/stdc++.h>
using namespace std;

int main() {
	int ar[4], total=0;
	for (int i = 0; i < 4; i++) {
		cin  >> ar[i];
	}
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		total+=ar[s[i]-49];
	}
	cout << total << endl;
}
