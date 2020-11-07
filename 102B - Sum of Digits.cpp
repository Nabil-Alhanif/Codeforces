#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string add(string s) {
	long long count=0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		count+=s[i]-'0';
	}
	stringstream ss;
	ss << count;
	ss >> s;
	return s;
}
int main() {
	string s;
	cin >> s;
	if (s.size()==1)  {
		cout << "0\n";
		return 0;
	} else {
		long long ans=0;
		while (true) {
			s = add(s);
			ans++;
			if (s.size()==1) {
				break;
			}
		}
		cout << ans << "\n";
	}
}
