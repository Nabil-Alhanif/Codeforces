#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int ar[m];
	for (int i = 0; i < m; i++) {
		cin >> ar[i];
	}
	sort(ar, ar+m);
	int least = -1;
	for (int i = 0; i < m-n+1; i++) {
		int dif = ar[i+n-1]-ar[i];
		if (least==-1||least>=dif)least=dif;
	}
	cout << least << "\n";
}
