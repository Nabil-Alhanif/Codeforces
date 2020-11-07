#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, bool> m;
		bool opt=true;
		int pos=-1;
		for (int i = 1; i <= n; i++) {
			int k;
			cin>>k;
			bool nikah=false;
			while(k--) {
				int tmp;
				cin>>tmp;
				if(!nikah) {
					if(!m[tmp]) {
						m[tmp]=true;
						nikah=true;
					}
				}
			}
			if(!nikah) {
				opt=false;
				pos=i;
			}
		}
		if(opt)cout<<"OPTIMAL\n";
		else {
			cout<<"IMPROVE\n";
			for (int i = 1; i <= n; i++) {
				if(!m[i]) {
					cout<<pos<<" "<<i<<"\n";
					break;
				}
			}
		}
	}
}
