#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp, ans=0;
	cin >> tmp;
	int less=tmp, more=tmp;
	n--;
	while (n--) {
		cin >> tmp;
		if (tmp>more) {
			more=tmp;
			ans++;
		}
		if (tmp<less) {
			less=tmp;
			ans++;
		}
	}
	cout << ans << "\n";
}
