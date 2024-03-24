#include <bits/stdc++.h>
using namespace std;
long long least, n, p, x, dp[1000001], a[1000001];
pair <long long, long long> arr[1000006];

int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i], &p);
		arr[i]= make_pair(a[i], p);
	}
	sort(a+1, a+n+1);
	sort(arr+1, arr+n+1);
	for (long long i = 1; i <= n; i++) {
		x = lower_bound(a+1, a+n+1, arr[i].first - arr[i].second)-a-1;
		dp[i]=dp[x]+1;
		least = max(least, dp[i]);
	}
	printf("%lld", n-least);
}
