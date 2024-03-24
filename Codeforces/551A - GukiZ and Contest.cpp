#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ar[n];
	vector<int>v;
	map<int,int>pos,m;
	for (int i=0;i<n;i++) {
		cin>>ar[i];
		if(!m[ar[i]])v.push_back(ar[i]);
		m[ar[i]]++;
	}
	sort(v.begin(),v.end(),greater<int>());
	int last=0;
	for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
		if (it!=v.begin()) {
			if(*it!=*(it-1))last+=m[*(it-1)];
			//cout<<"last: "<<last<<"\n";
		}
		pos[*it]=0+last;
	}
	for (int i = 0; i < n; i++) {
		cout<<pos[ar[i]]+1<<" ";
	}cout<<"\n";
}
