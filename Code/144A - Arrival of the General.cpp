#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int maks, mins, a=-1, b=INT_MAX;
	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		if (tmp>a) {
			a=tmp;
			maks=i;
		}
		if (tmp<=b) {
			b=tmp;
			mins=i;
		}
	}
	int ans=maks+t-mins-1;
	if (maks>mins)ans-=1;
	cout << ans << "\n";
}
