#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long ar[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ar[i]);
	}
	int day;
	scanf("%d", &day);
	sort(ar, ar+n);
	while (day--) {
		long long coin;
		scanf("%lld", &coin);
		long long temp = upper_bound(ar, ar+n, coin)-ar;
		printf("%lld\n", temp);
	}
}
