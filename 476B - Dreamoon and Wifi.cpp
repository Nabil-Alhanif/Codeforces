#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, double> m, m2;
	string s, s2;
	cin >> s >> s2;
	double size = s.length();
	for (double i = 0; i < size; i++) {
		m[s[i]]++;
		m2[s2[i]]++;
	}
	double one = 1;
	double zero = 0;
	if (m['+']==m2['+']&&m['-']==m2['-']) cout << fixed << setprecision(12) << one << "\n";
	else if (m2['+']>m['+']||m2['-']>m['-']) cout << fixed << setprecision(12) << zero << "\n";
	else {
		double q = m2['?'];
		double div = pow(2, q);
		double maks = max(m['+']-m2['+'], m['-']-m2['-']);
		double mins = min(m['+']-m2['+'], m['-']-m2['-']);
		double a = 1, b = 1;
		for (double c = q; c > maks; c--) {
			a*=c;
		}
		for (double d = mins; d> 0; d--) {
			b*=d;
		}
		double ans = a/(b*div);
		cout << fixed << setprecision(12) << ans;
	}
	
}
