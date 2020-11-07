#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 1; i*i<=n; i++) {
			v.push_back(i);
			v.push_back(n/i);
		}
		sort(v.begin(),v.end());
		vector<int>::iterator itr = unique(v.begin(),v.end());
		v.resize(distance(v.begin(),itr));
		cout<<v.size()+1<<"\n";
		cout<<0;
		for (auto i:v) {
			cout<<" "<<i;
		} cout<<"\n";
	}
}
