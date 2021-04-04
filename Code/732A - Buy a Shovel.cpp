#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int a, b, i=1, c;
	cin >> a >> b;
	c=a;
	while (true) {
		if (a%10==0||a%10==b) {
			break;
		}
		a+=c;
		i++;
	}
	cout << i << "\n";
}
