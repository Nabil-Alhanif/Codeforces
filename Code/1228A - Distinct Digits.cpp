#include <bits/stdc++.h>
using namespace std;
void cek(int x) {
	int y=x;
	map<int,int>m;
	int c=0;
	while (x>0) {
		m[x%10]++;
		c++;
		x/=10;
	}
	if(m.size()==c) {
		cout<<y<<"\n";
		exit(0);
	}
}
int main() {
	int l,r;
	cin>>l>>r;
	for (int i = l; i <= r; i++) {
		cek(i);
	}
	cout<<"-1\n";
}
