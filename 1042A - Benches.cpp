#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int bench, add, people=0, mins, maks;
	cin >> bench >> add;
	for (int i = 0; i < bench; i++) {
		int temp;
		cin >> temp;
		people=max(people, temp);
	}
	maks=people+add;
	if (add%bench!=0) {
		add/=bench;
		add++;
	} else {
		add/=bench;
	}
	mins = people+add;
	cout << mins << " " << maks << "\n";
}
