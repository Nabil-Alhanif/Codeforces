#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s, s1, s2;
	cin >> s >> s1 >> s2;
	s+=s1;
	sort(s.begin(), s.end());
	sort(s2.begin(),s2.end());
	if (s.compare(s2)==0)cout <<"YES\n";
	else cout << "NO\n";
}
