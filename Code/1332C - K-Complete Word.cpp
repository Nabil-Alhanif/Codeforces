#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		int index=(k+1)/2;
		vector<int> v[index];
		string s;
		cin>>s;
		for (int i = 0; i < n; i++) {
			int tmp=i%k;
			if(tmp>=index)tmp=k-tmp-1;
			v[tmp].push_back(s[i]-'a'+1);
		}
		int ans=0;
		for (int i = 0; i < index; i++) {
			int ar[30]={0},mins=0,si=v[i].size();
			for (auto j:v[i]) {
				ar[j]++;
				mins=max(mins,ar[j]);
			}ans+=si-mins;
		}
		cout<<ans<<"\n";
	}
}
