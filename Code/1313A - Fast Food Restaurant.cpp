#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--){
		int a1,b1,c1,a,b,c,ans=0;
		cin >>a1>>b1>>c1;
		if (a1>=b1&&a1>=c1) {
			a=a1;
			if (b1>=c1) {
				b=b1;
				c=c1;
			} else {
				b=c1;
				c=b1;
			}
		}
		if (b1>=a1&&b1>=c1) {
			a=b1;
			if (a1>=c1) {
				b=a1;
				c=c1;
			} else {
				b=c1;
				c=a1;
			}
		}
		if (c1>=a1&&c1>=b1) {
			a=c1;
			if (a1>=b1) {
				b=a1;
				c=b1;
			} else {
				b=b1;
				c=a1;
			}
		}
		if (a>0) {
			ans++;
			a--;
		}
		if (b>0) {
			ans++;
			b--;
		}
		if (c>0) {
			ans++;
			c--;
		}
		if (a>0&&b>0) {
			ans++;
			a--;
			b--;
		}
		if (a>0&&c>0) {
			ans++;
			a--;
			c--;
		}
		if (b>0&&c>0) {
			ans++;
			b--;
			c--;
		}
		if (a>0&&b>0&&c>0) {
			ans++;
		}
		cout << ans <<"\n";
	}
}
