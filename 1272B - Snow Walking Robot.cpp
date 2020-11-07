#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		map<char, int> m;
		string s;
		cin >> s;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			m[s[i]]++;
		}
		int t1 = min(m['U'], m['D']);
		int t2 = min(m['L'], m['R']);
		int ma = t1*2+t2*2;
		if (t1==0&&t2!=0||t2==0&&t1!=0)ma=2;
		cout << ma << "\n";
		if (t2==0&&t1!=0)cout << "UD";
		else if (t1==0&&t2!=0)cout << "LR";
		else{
			for (int i = 0; i < t1; i++) cout << 'D';
			for (int i = 0; i < t2; i++) cout << 'R';
			for (int i = 0; i < t1; i++) cout << 'U';
			for (int i = 0; i < t2; i++) cout << 'L';
		}
		
		cout << "\n";
	}
}
