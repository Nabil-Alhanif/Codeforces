#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	map<int,int>m;
	int n;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		m[tmp]++;
		if (tmp==100) {
			if (m[50]>0&&m[25]>0) {
				m[50]--;
				m[25]--;
			} else if (m[25]>2) {
				m[25]-=3;
			} else {
				cout<<"NO\n";
				return 0;
			}
		} else if (tmp==50) {
			if (m[25]>0) {
				m[25]--;
			}else {
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
}
