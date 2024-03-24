#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	map<int,bool> m;
	vector<int>v;
	int n;
	cin>>n;
	while (n--) {
		int tmp;
		cin>>tmp;
		if(!m[tmp])v.push_back(tmp);
		m[tmp]=true;
	}
	sort(v.begin(),v.end());
	if(v.size()>3) {
		cout<<"-1\n";
	} else {
		if(v.size()==1)cout<<"0\n";
		else if(v.size()==2) {
			int a=abs(v[1]-v[0]);
			if(a%2==0)cout<<a/2;
			else cout<<a<<"\n";
		}
		else if(v.size()==3) {
			int a=abs(v[2]-v[1]),b=abs(v[1]-v[0]);
			if(a==b) cout<<a<<"\n";
			else cout<<"-1\n";
		}
	}
}
