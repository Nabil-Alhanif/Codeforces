#include <bits/stdc++.h>
using namespace std;
inline double log(double base,double x) {
	return (log(x)/log(base));
}
int main() {
	int n, m,ans=0;
	cin>>n>>m;
	if (m%n) {
		cout<<"-1\n";
		return 0;
	}
	m/=n;
	while (!(m%6)) {
		m/=6;
		ans+=2;
	}
	while (!(m%2)) {
		m/=2;
		ans++;
	}
	while (!(m%3)) {
		m/=3;
		ans++;
	}
	if (m!=1) {
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<"\n";
}
