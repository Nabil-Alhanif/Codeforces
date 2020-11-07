#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long most = 0;
	unsigned long long ar[14], ar2[14];
	for (unsigned long long i = 0; i < 14; i++) {
		cin >> ar[i];
		ar2[i]=ar[i];
	}
	for (unsigned long long i = 0; i < 14; i++) {
		for (unsigned long long k = 0; k < 14; k++) {
			ar[k]=ar2[k];
		}
		unsigned long long total=0;
		vector<unsigned long long> v;
		unsigned long long temp = ar[i]/14;
		unsigned long long temp2 = ar[i]%14;
		ar[i]=0;
		for (unsigned long long j = 0; j < 14; j++) {
			unsigned long long te = i+j+1;
			v.push_back(ar[te%14]+temp);
		}
		unsigned long long t = 0;
		while (temp2--) {
			v[t]++;
			t++;
		}
		for (unsigned long long j = 0; j < 14; j++) {
			if (v[j]%2==0)total+=v[j];
		}
		if (total>most)most=total;
	}
	cout << most << "\n";
}
