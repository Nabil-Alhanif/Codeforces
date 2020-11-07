#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, car=0;
	cin >> n;
	int ar[4];
	memset(ar, 0, sizeof(ar));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ar[a-1]++;
	}
	car+=ar[3];
	car+=ar[2];
	car+=ar[1]/2;
	int b1 = ar[1]%2;
	int a1 = max(0, ar[0]-ar[2]);
	int a3 = a1+b1*2;
	if (a3%4==0) {
		car+=a3/4;
	} else car+=a3/4+1;
	cout << car << endl;
}
