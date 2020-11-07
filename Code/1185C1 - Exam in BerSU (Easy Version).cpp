#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ar[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		vector<int> v;
		int m2 = m-ar[i], home = 0;
		for (int j = 0; j < i; j++) {
			v.push_back(ar[j]);
		}
		sort(v.begin(),v.end());
		for (int j = 0; j < i; j++) {
			m2-=v[j];
			if (m2<0) {
				m2+=v[j];
				home++;
			}
		}
		cout << home << " ";
	} cout << "\n";
}
