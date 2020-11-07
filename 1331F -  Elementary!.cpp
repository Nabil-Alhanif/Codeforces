#include <bits/stdc++.h>
using namespace std;
vector<string> v={
"H","HE","LI","BE","B","C","N","O",
"F","NE","NA","MG","AL","SI","P","S",
"CL","AR","K","CA","SC","TI","V","CR",
"MN","FE","CO","NI","CU","ZN","GA","GE",
"AS","SE","BR","KR","RB","SR","Y","ZR",
"NB","MO","TC","RU","RH","PD","AG","CD",
"IN","SN","SB","TE","I","XE","CS","BA",
"LA","CE","PR","ND","PM","SM","EU","GD",
"TB","DY","HO","ER","TM","YB","LU","HF",
"TA","W","RE","OS","IR","PT","AU","HG",
"TL","PB","BI","PO","AT","RN","FR","RA",
"AC","TH","PA","U","NP","PU","AM","CM",
"BK","CF","ES","FM","MD","NO","LR","RF",
"DB","SG","BH","HS","MT","DS","RG","CN",
"NH","FL","MC","LV","TS","OG"
};
bool beneranCuk=0;
void cariYuk(string s, int size){
	if (size==0) {
		beneranCuk=1;
		cout<<"YES\n";
		exit(0);
	}
	for (auto k:v) {
		int tmp=k.size();
		if(tmp<=size){
			if(s.substr(0,tmp)==k) {
				cariYuk(s.substr(0+tmp,size-tmp),size-tmp);
			}
		}
	}
} 
int main() {
	string s;
	cin>>s;
	cariYuk(s,s.size());
	cout<<"NO\n";
}
