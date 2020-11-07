#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	int score[n], time[n];
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	int limak=0, radewoosh=0, tl=0, tr=0;
	for (int i = 0; i < n; i++) {
		tl+=time[i];
		tr+=time[n-1-i];
		limak+=max(0, score[i]-tl*c);
		radewoosh+=max(0, score[n-1-i]-tr*c);
	}
	if (limak>radewoosh) cout << "Limak" << endl;
	else if (limak<radewoosh) cout << "Radewoosh" << endl;
	else cout << "Tie" << endl;
}
