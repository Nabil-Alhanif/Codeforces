#include <bits/stdc++.h>
using namespace std;

int main() {
	int pile;
	scanf("%d", &pile);
	long long worm[pile];
	for (int i = 0; i < pile; i++) {
		long long worms;
		scanf("%lld", &worms);
		if (i==0) {
			worm[i]=worms;
		} else {
			worm[i]=worms+worm[i-1];
		}
	}
	int query;
	scanf("%d", &query);
	while (query--) {
		long long juicyWorm;
		scanf("%lld", &juicyWorm);
		long long temp = lower_bound(worm, worm+pile, juicyWorm)-worm+1;
		printf("%lld\n", temp);
	}
}
