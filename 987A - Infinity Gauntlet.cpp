#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v;
	string ar[n];
	string ar2[6] = {"green", "blue", "orange", "red", "yellow", "purple"};
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int k = 0;
	while (k < 6) {
		int j = 0;
		while (j < n) {
			if (ar2[k]==ar[j]) {
				ar2[k] = "0";
			}
			j++;
		}
		k++;
	}
	for (int i = 0; i < 6; i++) {
		if (ar2[i]!="0") {
			v.push_back(ar2[i]);
		}
	}
	int size = v.size();
	cout << size << endl;
	for (int k = 0; k < size; k++) {
		if (v[k]=="purple") cout << "Power" << endl;
		if (v[k]=="green") cout << "Time" << endl;
		if (v[k]=="blue") cout << "Space" << endl;
		if (v[k]=="red") cout << "Reality" << endl;
		if (v[k]=="orange") cout << "Soul" << endl;
		if (v[k]=="yellow") cout << "Mind" << endl;
	}
}
