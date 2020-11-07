#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int size;string s;
	cin >> size >>s;
	int i = 0;
	while (i<size-1) {
		if (s[i]!=s[i+1]) {
			s.erase(i,2);
			size-=2;
			i-=2;
			if (i<0)i=-1;
		}
		i++;
	}
	cout <<size << "\n";
}
