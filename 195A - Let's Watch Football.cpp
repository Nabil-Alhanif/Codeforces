#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int time = a*c;
	if (time%b!=0) {
		time/=b;
		time+=1;
	} else {
		time/=b;
	}
	cout << time-c << "\n";
}
