#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long r, g, b, total, min1, max1, mid;
		scanf("%lld %lld %lld", &r, &g, &b);
		total = r+g+b;
		min1=min(r, min(g, b));
		max1=max(r, max(g, b));
		mid=total-min1-max1;
		max1-=mid;
		if (max1-min1>1) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
}
