#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int time[n];
	time[0]=0;
	for (int i=1; i<n;i++) {
		cin >> time[i];
		time[i]+=time[i-1];
	}
	int a, b;
	cin >> a >> b;
	cout << time[b-1]-time[a-1]<<"\n";
}
