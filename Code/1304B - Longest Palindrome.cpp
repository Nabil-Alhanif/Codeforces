#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, int> m;
string a1, a2, a3;
bool dah=false;
ll cou=0;
void cek(string s, ll size) {
	string s1;
	for (int i = size-1; i >= 0; i--) {
		s1+=s[i];
	}
	if (s==s1 &&!dah) {
		a2=s;
		cou++;
		dah=true;
	} else {
		if (m[s1]!=0) {
			a1=s1+a1;
			a3+=s;
			cou+=2;
		}
	}
}
int main() {
	ll n, d;
	cin >> n >> d;
	while (n--) {
		string s;
		cin >> s;
		cek(s, d);
		m[s]++;
	}
	cout << cou*d<<"\n";
	cout<<a1<<a2<<a3<<"\n";
}
