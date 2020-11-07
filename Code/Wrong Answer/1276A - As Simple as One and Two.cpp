#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int size = s.size();
		vector<int> v;
		int kon=0;
		for (int i = 0; i < size-2; i++) {
			if (s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o') {
				s.erase(i+2, 1);
				v.push_back(i+3+kon);
				kon++;
				size--;
			}
		}
		for (int i = 0; i < size-2; i++) {
			if (s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e') {
				s.erase(i+2,1);
				v.push_back(i+3+kon);
				kon++;
				size--;
			}
		}
		cout << v.size() << "\n";
		for (auto i : v) {
			cout << i << " ";
		} cout << "\n";
	}
}
