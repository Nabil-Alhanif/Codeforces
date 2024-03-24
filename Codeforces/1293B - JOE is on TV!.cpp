#include <bits/stdc++.h>
using namespace std;

int main() {
	double t;
	cin >> t;
	double ans=0.0;
	for (t; t>0; t--) {
		ans+=double(1)/t;
	}
	cout <<setprecision(9)<<fixed<< ans << "\n";
}
