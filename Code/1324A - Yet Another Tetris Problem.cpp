#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int c, p;
		cin >> c;
		bool samePar=true;
		for (int i = 0; i < c; i++) {
			int tmp;
			cin >> tmp;
			if (i==0) p=tmp%2;
			else {
				if (p!=tmp%2) samePar=false;
			}
		}
		if (samePar)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
