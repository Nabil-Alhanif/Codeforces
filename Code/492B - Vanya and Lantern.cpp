#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	bool ketemu = false, k2 = false;
	cin >> n >> l;
	vector<double> v;
	for (int i = 0; i < n; i++) {
		double t;
		cin >> t;
		if (t==0) ketemu=true;
		if (t==l) k2 = true;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	double dif=0;
	for (int i = 1; i < n; i++) {
		double temp = v[i]-v[i-1];
		if (temp>=dif) dif = temp;
	}
	dif/=2;
	if(!ketemu){
		dif = max(v[0], dif);
	}
	if (!k2) {
		dif = max(l-v[n-1], dif);
	}
	cout << fixed << setprecision(12) << dif << "\n";
}
