#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;int k,size;
	cin>>size>>k>>s;
	for (int i=0;i<k&&i<size;i++) {
		if(i==0) {
			if(size>1) {
				if(s[i]!='1')s[i]='1';
				else k++;
			} else {
				if(s[i]!='0')s[i]='0';
				else k++;
			}
		} else {
			if (s[i]!='0')s[i]='0';
			else k++;
		}
	}
	cout<<s<<"\n";
}
