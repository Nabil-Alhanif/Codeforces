#include <bits/stdc++.h>
using namespace std;
int main() {
	int size;
	string s;
	cin >>  size>>s;
	int ar[10]={0};
	for (int i = 0; i < size; i++) {
		if (s[i]=='L') {
			for (int j = 0; j < 10; j++) {
				if (ar[j]==0) {
					ar[j]=1;
					break;
				}
			}
		} else if (s[i]=='R') {
			for (int j = 9; j >= 0; j--) {
				if (ar[j]==0) {
					ar[j]=1;
					break;
				}
			}
		} else {
			ar[s[i]-'0']=0;
		}
		
	}
	for (int i = 0;i < 10; i++) {
		cout <<ar[i];
	}cout<<"\n";
}
