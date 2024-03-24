#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main() {
	int n;
	scanf("%d", &n);
	long long z=1;
	long long j = 2;
	long long count = 1;
	for (int i = 1; i < n; i++) {
		count%=mod;
		j%=mod;
		z%=mod;
		count+=j;
		j+=z;
		z=j-z;
		count%=mod;
		j%=mod;
		z%=mod;
	}
	count%=mod;
	printf("%lld", count);
}
