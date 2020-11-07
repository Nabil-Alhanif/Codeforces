#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, ma;
	cin >> n >> ma;
	map<string, string> m;
	while(ma--) {
		string s, s1;
		cin >>s>>s1;
		if (s.length()<=s1.length())m[s]=s;
		else m[s]=s1;
	}
	string ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		cout << m[ar[i]]<<" ";
	}cout<<"\n";
}
