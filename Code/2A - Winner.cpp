#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,maks=INT_MIN;
	cin >> n;
	pair<string, int> ar[n];
	map<string, int> score,m,comp;
	map<string, bool> winner;
	vector<string> player,wins;
	for (int i = 0; i < n; i++) {
		string s;
		int tmp;
		cin >> s >> tmp;
		ar[i]={s,tmp};
		score[s]+=tmp;
		m[s]++;
		if(m[s]==1)player.push_back(s);
	}
	for (auto i:player) {
		maks=max(maks, score[i]);
		//cout<<i<<"\n";
	}
	//cout <<maks<<"\n";
	for (auto i:player) {
		if(score[i]==maks) {
			winner[i]=true;
			wins.push_back(i);
		}
	}
	//for(auto i:player){if(winner[i]){cout<<i<<"\n";}}
	if(wins.size()==1)cout<<wins[0]<<"\n";
	else {
		for (int i = 0; i < n; i++) {
			comp[ar[i].first]+=ar[i].second;
			//cout << ar[i].first<<" "<<comp[ar[i].first]<<"\n";
			if (winner[ar[i].first]) {
				if(comp[ar[i].first]>=maks) {
					cout<<ar[i].first<<"\n";
					return 0;
				}
			}
		}
	}
}
