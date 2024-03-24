#include <bits/stdc++.h>
using namespace std;
int divi[11]={2,3,5,7,11,13,17,19,23,29,31};
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int dar[33];
		pair<int,int> ar[n];
		map<int,bool> m;
		for (int i = 0; i < n; i++) {
			int tmp,tmp2=2;
			cin>>tmp;
			for (int j = 0; j < 11; j++) {
				if(tmp%divi[j]==0) {
					if (!m[divi[j]]) {
						m[divi[j]]=true;
						dar[j]=m.size();
					}
					tmp2=dar[j];
					break;
				}
			}
			ar[i]={tmp,tmp2};
		}
		cout<<m.size()<<"\n";
		for (int i = 0; i < n; i++) {
			cout<<ar[i].second;
			if(i<n-1)cout<<" ";
		}cout<<"\n";
	}
}
