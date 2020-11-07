#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	pair<int, int> ar[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ar[i]=make_pair(tmp, i+1);
	}
	sort(ar, ar+n);
	for (int i = 0; i < n; i++) {
		cout << ar[i].second;
		if (i!=n-1)cout<<" ";
	} cout << "\n";
}
