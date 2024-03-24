#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<int> v;
int main() {
	ull n, m;
	cin >> n >> m;
	ull a=1, move=0;
	while (m--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i]>=a) {
			move += v[i]-a;
			a=v[i];	
		} else {
			move+=v[i]+n-a;
			a=v[i];
		}
	}
	cout << move << "\n";
}
