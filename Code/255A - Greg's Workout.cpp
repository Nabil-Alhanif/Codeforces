#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,maks=0;
	string s,lis[3]={"chest\n","biceps\n","back\n"};
	cin>>n;
	int ar[3]={0};
	for (int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		ar[i%3]+=tmp;
		if (ar[i%3]>maks) {
			maks=ar[i%3];
			s=lis[i%3];
		}
	}
	cout<<s;
}
