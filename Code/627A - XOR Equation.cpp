#include <bits/stdc++.h>
using namespace std;
long long search(long long a, long long b) {
	if (b>a||(a-b)%2==1) {
		return 0;
	}
	if ((a-b)/2&b!=0) {
		return 0;
	}
	long long power = __builtin_popcountll(b);
	long long count = pow(2, power);
	if (a==b)count-=2;
	return count;
}
int main() {
	long long s, x;
	scanf("%lld %lld", &s, &x);
	long long count = search(s, x);
	printf("%lld\n", count);
}
