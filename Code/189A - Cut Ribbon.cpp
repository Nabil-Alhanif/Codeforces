#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, t1, t2, t3;
	cin >> n >> a >> b >> c;
	int ar[n+1];
	ar[0]=0;
	for (int i = 1; i <= n; i++) {
		t1=t2=t3=-1;
		if (i>=a) {
			t1=ar[i-a];
		}
		if (i>=b) {
			t2=ar[i-b];
		}
		if (i>=c) {
			t3=ar[i-c];
		}
		if (t1==-1&&t2==-1&&t3==-1) {
			ar[i]=-1;
		} else {
			ar[i]=max(t1, max(t2, t3))+1;
		}
	}
	cout << ar[n] << "\n";
}
