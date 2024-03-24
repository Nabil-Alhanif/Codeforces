#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[2001];
int main() {
	ll n, maks=0;
	cin>> n;
	vector<int> v[n+1];
	ll p[n+1];
	for (int i = 0; i <n; i++) {
		ll tmp;
		cin >> tmp;
		p[i+1]=tmp;
		if (tmp!=-1) {
			v[tmp].push_back(i+1);
			b[tmp]=true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			ll tmp=1;
			ll pos=p[i];
			while (pos!=-1) {
				pos=p[pos];
				tmp++;
			}
			maks=max(maks, tmp);
		}
	}
	cout << maks << "\n";
}
