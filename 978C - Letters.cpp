#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull room[200005], query[200005];

int main() {
	ull n, m;
	scanf("%llu %llu", &n, &m);
	room[0]=0;
	for (ull i = 1; i <= n; i++) {
		ull r;
		scanf("%llu", &r);
		room[i]=room[i-1]+r;
	}
	for (ull i = 1; i<= m; i++) {
		ull c;
		scanf("%llu", &c);
		query[i]=c;
	}
	for (ull i = 1; i <=m; i++) {
		ull tmp = lower_bound(room, room+n, query[i])-room;
		printf("%llu %llu\n", tmp, query[i]-room[tmp-1]);
	}
}
