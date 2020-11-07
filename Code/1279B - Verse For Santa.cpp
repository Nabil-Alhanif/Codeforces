#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll n, s;
		scanf("%lld %lld", &n, &s);
		ll t=0, index=0, nilai=0, maks=0;
		ll ar[n];
		bool pas=false;
		while (t<n) {
			ll tmp;
			scanf("%lld", &tmp);
			ar[t]=tmp;
			if (t!=0)ar[t]+=ar[t-1];
			maks=max(maks, tmp);
			if (ar[t]-maks<=s) {
				if (maks==tmp) {
					index=t+1;
				}
			}
			t++;
		}
		if (ar[n-1]<=s) {
			index=0;
		}
		printf("%lld\n", index);
	}
}
