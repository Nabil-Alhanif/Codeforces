#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string s, temp1, temp2, temp3, last;
	cin >> s;
	int size = s.length();
	bool can=false;
	for (int i = 0; i < size; i++) {
		temp1=s[i];
		stringstream s1;
		int t1;
		s1 << temp1;
		s1 >> t1;
		if (t1%8==0) {
			can=true;
			last=temp1;
		} else {
			for (int j = i+1; j < size; j++) {
				temp2 = temp1+s[j];
				stringstream s2;
				s2 << temp2;
				s2 >> t1;
				if (t1%8==0) {
					can = true;
					last=temp2;
				} else {
					for (int k = j+1; k < size; k++) {
						temp3 =temp2+s[k];
						stringstream s3;
						s3 << temp3;
						s3 >> t1;
						if (t1%8==0) {
							can = true;
							last = temp3;
							break;
						}
					}
				}
				if (can)break;
			}
		}
		if (can) break;
	}
	if (can) {
		cout << "YES\n" << last << "\n";
	} else {
		cout << "NO\n";
	}
}
