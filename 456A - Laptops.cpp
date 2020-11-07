#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
vector<int> v;
int main() {
	bool happy = false;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(a);
		m[a]=b;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i]<v[i+1]) {
			if (m[v[i]]>m[v[i+1]]) {
				happy = true;
				break;
			}
		}
	}
	if (happy) cout << "Happy Alex" << endl;
	else cout << "Poor Alex" << endl;
}
