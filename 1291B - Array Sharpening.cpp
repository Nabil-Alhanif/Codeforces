#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		if (n%2==1) {
			bool bisa=true;
			for (int i = 0; i < (n/2)+1; i++) {
				if (ar[i]<i) {
					bisa=false;
					break;
				}
			}
			if (bisa) {
				for (int i = (n/2)+1; i < n; i++) {
					if (ar[i]<n-1-i) {
						bisa=false;
						break;
					}
				}
			}
			if (bisa)cout << "YES\n";
			else cout << "NO\n";
		} else {
			bool bisa=true,bisa2=true;
			for (int i = 0; i < (n/2)+1; i++) {
				if (ar[i]<i) {
					bisa=false;
					break;
				}
			}
			if (bisa) {
				for (int i = (n/2)+1; i < n; i++) {
					if (ar[i]<n-1-i) {
						bisa=false;
						break;
					}
				}
			}
			if (!bisa) {
				for (int i = 0; i < (n/2)-1; i++) {
					if (ar[i]<i) {
						bisa2=false;
						break;
					}
				}
				if (bisa2) {
					for (int i = (n/2)-1; i < n; i++) {
						if (ar[i]<n-1-i) {
							bisa2=false;
							break;
						}
					}
				}
			}
			if (bisa||bisa2)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
