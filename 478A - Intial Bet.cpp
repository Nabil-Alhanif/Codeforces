#include <bits/stdc++.h>
using namespace std;
int main() {
	int tot=0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		tot+=tmp;
		
	}
 	cout<<(tot%5==0&&tot!=0?tot/5:-1)<<"\n";
 }
