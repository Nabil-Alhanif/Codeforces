#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a=0;
	cin >> n;
	int b = n;
	string s;
	cin >> s;
	vector<char> v;
	while (b > 0) {
		a+=1;
		b -= a;
	}
	int j = 0;
	int i = 1;
	while (j < n) {
		j+=i;
		char c = s[j-1];
		v.push_back(c);
		i++;
	}
	for (int k = 0; k < a; k++) {
		cout << v[k];
	}
	cout << endl;
}
