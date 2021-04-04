#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n, ans=0;
	cin >> n;
	string s, s1;
	cin >> s >> s1;
	for (int i = 0; i < n; i++) {
		ans+=min(max(s[i],s1[i])-min(s[i],s1[i]),(min(s[i],s1[i])+10-max(s[i], s1[i]))%10);
	}
	cout << ans << "\n";
}
