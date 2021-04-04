#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, safe = 0;
	cin >> t;
	string s;
	cin >> s;
	bool findr=false;
	int q=-1, p=-1;
	for (int i = 0; i < t; i++) {
		if (s[i]=='L'&&!findr) {
			q=i;
		} else if (s[i]=='L'&&findr) {
			q = i;
			safe+=(q-p-1)%2;
		}
		else if (s[i]=='R') {
			if (q!=-1) safe+=i-q-1;
			else if (q==-1) {
				safe+=i;
			}
			p=i;
			findr=true;
		}
	}
	if (q>p) {
		safe+=t-1-q;
	}
	if (q==-1&&!findr)safe=t;
	cout << safe << "\n";
}
