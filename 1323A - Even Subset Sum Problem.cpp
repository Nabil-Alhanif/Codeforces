#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int h;
		cin >> h;
		int a=0, b=0, c=0;
		for (int i = 1; i<=h;i++) {
			int tmp;
			cin >> tmp;
			if (tmp%2==0) {
				c=i;
			} else {
				if (a==0) {
					a=i;
				} else {
					b=i;
				}
			}
		}
		if (c!=0) {
			cout <<"1\n"<<c<<"\n";
		} else {
			if (a!=0&&b!=0) {
				cout << "2\n"<<a<<" "<<b<<"\n";
			} else cout <<"-1\n";
		}
	}
}
