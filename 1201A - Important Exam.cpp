#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, score=0;
	cin >> a >> b;
	string ar[a];
	int po[b];
	for (int i = 0; i < a; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> po[i];
	}
	for (int i = 0; i < b; i++) {
		int total = 0, d=0,e=0,f=0,g=0,h=0;
		for (int j = 0; j < a; j++) {
			if (ar[j][i]=='A') d++;
			if (ar[j][i]=='B') e++;
			if (ar[j][i]=='C') f++;
			if (ar[j][i]=='D') g++;
			if (ar[j][i]=='E') h++;
		}
		int temp = max(d, max(e,max(f, max(g, h))));
		score+=temp*po[i];
	}
	cout << score << endl;
}
