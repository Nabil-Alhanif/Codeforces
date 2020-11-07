#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, k, hitung=0;
	cin >> n >> k;
	string s;
	cin >> s;
	map<string, ll> m;
	if (k==n)cout << 1 << "\n";
	else if (k>n)cout << 0 << "\n";
	else {
		for (int i = 0; i <= n-k; i++) {
			string s2=s.substr(i,k);
			m[s2]++;
		}
		cout << m.size()<<"\n";
	}
}
