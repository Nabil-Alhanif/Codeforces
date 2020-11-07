#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int size=s.size();
	for (int i = 0; i < size; i++) {
		int tmp=s[i]-'0';
		if (tmp>=5&&(i||tmp!=9)) {
			s[i]='0'+(9-tmp);
		}
		cout<<s[i];
	}cout<<"\n";
}
