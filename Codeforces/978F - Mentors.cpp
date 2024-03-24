#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	int ar[n], ar2[n], ar3[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
		ar2[i]=ar[i];
	}
	sort(ar2, ar2+n);
	for (int i = 0; i < n; i++) {
		int temp = ar[i];
		ar3[i]=lower_bound(ar2, ar2+n, ar[i]) - ar2;
	}
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (ar[a-1]>ar[b-1]) ar3[a-1]--;
		else if (ar[b-1]>ar[a-1]) ar3[b-1]--;
	}
	for (int i = 0; i < n; i++) {
		cout << ar3[i] << " ";
	} cout << "\n";
}
