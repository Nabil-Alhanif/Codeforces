#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, ans=0, mins=0;
	cin >> t;
	while (t--) {
		int tmp;
		cin >> tmp;
		ans+=tmp;
		if (ans<0) {
			mins+=ans;
			ans=0;
		}
	}
	cout << abs(mins) << "\n";
}
