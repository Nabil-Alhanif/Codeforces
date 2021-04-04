#include <bits/stdc++.h>
using namespace std;
int vowels[6]={'A','E','I','O','U','Y'};
int main() {
	string s;
	cin>>s;
	int pos=-1,size=s.size(),ans=0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 6; j++){
			if (s[i]==vowels[j]) {
				ans=max(ans,i-pos);
				pos=i;
				break;
			}
		}
	}
	ans=max(ans,size-pos);
	cout<<ans<<"\n";
}
