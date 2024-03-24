#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (y<=x) {
			cout << "YES\n";
		} else if(x==2&&y==3||x==3&&y==2) {
			cout << "YES\n";
		} else {
			if (x!=2&&x!=3&&x!=1) {
				cout << "YES\n";
			}else cout << "NO\n";
		}
	}
}
