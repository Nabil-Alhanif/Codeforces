#include <bits/stdc++.h>
using namespace std;
int main() {
	int tr=0,med=0,n;
	for (int i = 0; i < 3; i++) {
		int tmp;
		cin >> tmp;
		tr+=tmp;
	}
	for (int i = 0; i < 3; i++) {
		int tmp;
		cin>>tmp;
		med+=tmp;
	}
	cin >> n;
	int meds=med/10+(med%10==0?0:1);
	int tro=tr/5+(tr%5==0?0:1);
	cout<<(meds+tro<=n?"YES\n":"NO\n");
}
