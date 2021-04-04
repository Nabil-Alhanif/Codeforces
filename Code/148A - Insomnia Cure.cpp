#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int k, l, ma, n, d, ans=0;
	cin >> k >> l >> ma >> n >> d;
	int ar[d+1];
	for (int i = 1; i <= d; i++) {
		ar[i]=1;
	}
	for (int i = 0;i<= d; i+=k) {
		ar[i]=0;
	}
	for (int i = 0;i<= d; i+=l) {
		ar[i]=0;
	}
	for (int i = 0;i<= d; i+=ma) {
		ar[i]=0;
	}
	for (int i = 0;i<= d; i+=n) {
		ar[i]=0;
	}
	for (int i = 1;  i <= d; i++) {
		if (ar[i]==1)ans++;
	}
	cout << d-ans << "\n";
}
