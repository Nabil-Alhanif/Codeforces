#include <bits/stdc++.h>
using namespace std;

char ar[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	while (m--) {
		char a, b;
		cin >> a >> b;			
		int t, t2;
		for (int i = 0; i < 26; i++) {

			if (ar[i]==a) t = i;
			if (ar[i]==b) t2 = i;
		}
		swap(ar[t],ar[t2]);
	}
	for(int i = 0; i < s.length(); i++){
		cout<<ar[s[i]-'a'];
	}cout<<endl;
}
