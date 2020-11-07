#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) {
		ll candy, kid;
		scanf("%lld %lld", &candy, &kid);
		ll given=0;
		ll tmp = (candy/kid)*kid;
		candy-=tmp;
		given+=tmp;
		given+=min(candy, (kid/2));
		printf("%lld\n", given);
	}
}
