#include <bits/stdc++.h>
using namespace std;

int main() {
	bool x=false, y=false, z=false;
	vector<string> name;
	vector<int> taxi, pizza, girl;
	int n; 
	cin >> n;
	int n2 = n;
	while (n2--) {
		int t, taaxi=0, piza=0, girls=0;
		string s;
		cin >> t >> s;
		name.push_back(s);
		while (t--) {
			string s2;
			cin >> s2;
			char s3 = s2[0];
			if (s3==s2[1]&&s3==s2[3]&&s3==s2[4]&&s3==s2[6]&&s3==s2[7]) taaxi+=1;
			else if (s3>s2[1]&&s2[1]>s2[3]&&s2[3]>s2[4]&&s2[4]>s2[6]&&s2[6]>s2[7]) piza +=1;
			else girls+=1;
		}
		taxi.push_back(taaxi);
		pizza.push_back(piza);
		girl.push_back(girls);
	}
	int maxt=taxi[0], maxp=pizza[0], maxg=girl[0];
	for (int i = 1; i < n; i++) {
		if (taxi[i]>=maxt)maxt=taxi[i];
		if (pizza[i]>=maxp)maxp=pizza[i];
		if (girl[i]>=maxg)maxg=girl[i];
	}
	vector<string> tname, pname, gname;
	for (int i=0; i < n; i++) {
		if (taxi[i]==maxt) {
			tname.push_back(name[i]);
		}
		if (pizza[i]==maxp) {
			pname.push_back(name[i]);
		}
		if (girl[i]==maxg) {
			gname.push_back(name[i]);
		}
	}
	cout << "If you want to call a taxi, you should call: ";
	for (int i = 0; i < tname.size(); i++) {
		cout << tname[i];
		if (i==tname.size()-1) cout << ".";
		else cout << ", ";
	}cout << endl;
	cout << "If you want to order a pizza, you should call: ";
	for (int i = 0; i < pname.size(); i++) {
		cout << pname[i];
		if (i==pname.size()-1) cout << ".";
		else cout << ", ";
	}cout << endl;
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for (int i = 0; i < gname.size(); i++) {
		cout << gname[i];
		if (i==gname.size()-1) cout << ".";
		else cout << ", ";
	}cout << endl;
}
