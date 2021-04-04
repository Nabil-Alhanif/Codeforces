#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int s;
		cin >> s;
		bool pal=false;
		map<int, pair<int,int> > m;
		for (int i=1; i <=s;i++) {
			int tmp;
			cin >> tmp;
			if (m[tmp].first>=1&&i-m[tmp].second>1)pal=true;
			m[tmp]={m[tmp].first+1, (m[tmp].second==0?i:m[tmp].second)};
		}
		cout<<(pal?"YES\n":"NO\n");
	}
}
