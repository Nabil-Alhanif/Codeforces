#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	string s; int n;
	cin >>  s >> n;
	if (n==0) {
		cout << s<< "\n";
		return 0;
	}
	int size = s.size();
	for (int i = 0; i < size; i++) {
		char maks=s[i];int index=i;
		for (int j = i+1; j <= i+n&&j<size; j++) {
			if (s[j]>maks) {
				maks=s[j];
				index=j;
			}
		}
		if (index!=i) {
			n-=(index-i);
			for (int j = i; j <=index; j++) {
				swap(s[i], s[j]);
			}
		}
		if (n==0)break;
	}
	cout << s<< "\n";
}
