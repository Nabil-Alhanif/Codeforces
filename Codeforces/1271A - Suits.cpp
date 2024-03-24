#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int typeOne=a, typeTwo=min(b, c);
	long long prosperity=0;
	if (e>f) {
		prosperity+=min(d, typeOne)*e;
		d=max(0, d-typeOne);
		prosperity+=min(d, typeTwo)*f;
	} else {
		prosperity+=min(d, typeTwo)*f;
		d=max(0, d-typeTwo);
		prosperity+=min(d, typeOne)*e;
	}
	printf("%lld\n", prosperity);
}
