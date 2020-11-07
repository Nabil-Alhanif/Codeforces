#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans=0, c=0;
	cin >> n;
	int ar[n+1],ar2[n+1];
	ar[0]=0;
	for (int  i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		ar2[i]=tmp;
		if (tmp==1) {
			ar[i]=max(0, ar[i-1]-1);
			c++;
		}
		else ar[i]=ar[i-1]+1;
		ans=max(ans, ar[i]);
	}
	if (n==1) {
		if (ar2[1]==1)cout << 0 << "\n";
		else cout << 1 << "\n";
	} else if (c==n) {
		cout << c-1 << "\n";
	} else cout << ans+c << "\n";
}
