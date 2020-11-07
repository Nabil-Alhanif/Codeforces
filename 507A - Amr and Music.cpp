#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	pair<int,int>ar[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		ar[i]={tmp,i+1};
	}
	sort(ar,ar+n);
	int time=0,coun=0;
	for (int i = 0; i < n; i++) {
		time+=ar[i].first;
		if(time<=k)coun++;
	}
	cout<<coun<<"\n";
	for(int i = 0;i<coun;i++) {
		cout<<ar[i].second<<" ";
	}cout<<"\n";
}
