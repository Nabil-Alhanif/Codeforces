#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, ans=0;
	cin >> t;
	while (t>0) {
		if (t%2==1)ans++;
		t/=2;
	}
	cout << ans << "\n";
}
