#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v, v2;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			v.push_back(make_pair(a, i));
		}
		sort(v.begin(), v.end());
		int count = 0;
		if (n==2||m<n) {
			printf("-1\n");
			v.clear();
			v2.clear();
			continue;
		}
		for (int i = 1; i < n; i++) {
			v2.push_back(make_pair(v[i-1].second, v[i].second));
			count+=v[i-1].first+v[i].first;
		}
		v2.push_back(make_pair(v[0].second, v[n-1].second));
		count+=v[0].first+v[n-1].first;
		int sisa = m-n;
		for (int i = 0; i < sisa; i++) {
			v2.push_back(make_pair(v[0].second, v[1].second));
			count+=v[0].first, v[1].first;
		}
		printf("%d\n", count);
		for (int i = 0; i < m; i++) {
			printf("%d %d\n", v2[i].first, v2[i].second);
		}
		v.clear();
		v2.clear();
	}
}
