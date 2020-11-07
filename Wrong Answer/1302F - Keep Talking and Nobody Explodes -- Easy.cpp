#include <bits/stdc++.h>
using namespace std;
inline void add(int *a, int b) {
	*a+=b;
	*a%=10;
}

inline bool par(int a) {
	return (a%2==0?true:false);
}

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int ar[6];
	for (int i = 1; i <= 5; i++) {
		ar[i]=s[i-1]-'0';
	}
	
	if (ar[1]+ar[4]>10) add(&ar[1],3);
	else add(&ar[4],8);
	
	if (ar[3]+ar[2]>8) add(&ar[4],9);
	else add(&ar[5],8);
	
	if (!par(ar[3])) add(&ar[3],3);
	else add(&ar[3],4);
	
	if(ar[5]>ar[2]) add(&ar[4],1);
	else add(&ar[2],7);
	
	if (!par(ar[1])) add(&ar[1],3);
	else add(&ar[3],5);
	
	if (!par(ar[4])) add(&ar[4],7);
	else add(&ar[1],9);
	
	if (ar[4]>ar[1]) add(&ar[4],9);
	else add(&ar[4],2);
	
	if (ar[1]>ar[3]) add(&ar[2],1);
	else add(&ar[3],1);
	
	if (ar[5]>ar[3]) add(&ar[4],5);
	else add(&ar[5],8);
	
	if (ar[1]+ar[3]>8) add(&ar[4],5);
	else add(&ar[2],5);
	
	if (ar[1]>ar[4]) add(&ar[4],3);
	else add(&ar[2],3);
	
	if (ar[3]+ar[1]>9) add(&ar[2],9);
	else add(&ar[2],2);
	
	if (ar[4]+ar[3]>10) add(&ar[4],7);
	else add(&ar[5],7);
	
	if (ar[3]>ar[2]) add(&ar[3],2);
	else add(&ar[4],6);
	
	if (ar[1]>ar[3]) add(&ar[1],9);
	else add(&ar[2],9);
	
	if (!par(ar[3])) add(&ar[3],9);
	else add(&ar[1],5);
	
	if (ar[3]+ar[5]>9) add(&ar[3],4);
	else add(&ar[3],9);
	
	if (ar[3]>ar[1]) add(&ar[5],1);
	else add(&ar[5],7);
	
	if (ar[1]>ar[3]) add(&ar[2],9);
	else add(&ar[4],6);
	
	if (ar[2]=ar[3]>10) add(&ar[2],2);
	else add(&ar[3],6);
	for (int i = 1; i <= 5; i++) {
		cout << ar[i];
	}cout << "\n";
}
