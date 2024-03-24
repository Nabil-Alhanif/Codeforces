#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	bool lanjut = true, ok = true;
	int a, b;
	cin >> a >> b;
	v.push_back(b);
	while(b!=0&&b!=a) {
		if (b%10==1) {
			b-=1;
			b/=10;
			v.push_back(b);
		}
		else if (b%2==0) {
			b/=2;
			v.push_back(b);
		} else {
			break;
		}
	}
	if (b!=a) {
		cout << "NO\n";
		ok = false;
	}
	if (ok) {
		cout << "YES\n";
		int size = v.size();
		cout << size << "\n";
		for (int i = size-1; i >= 0;i--) cout << v[i] << " ";
		cout << "\n";
	}
}
