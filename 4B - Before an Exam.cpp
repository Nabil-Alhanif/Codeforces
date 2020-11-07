#include <bits/stdc++.h>
using namespace std;
int main() {
	int d, sumTime,maks=0;
	bool bisa=true;
	cin >> d >> sumTime;
	pair<int, int> time[d];
	for (int i = 0; i < d; i++) {
		int tmp,b;
		cin >> b>>tmp;
		sumTime-=b;
		if (sumTime<0)bisa=false;
		time[i]={b,tmp};
		maks+=tmp-b;
	}
	if(sumTime>maks)bisa=false;
	if(!bisa)cout<<"NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < d; i++) {
			int dif=time[i].second-time[i].first;
			time[i]={time[i].first+(sumTime-dif<0?sumTime:dif),time[i].second};
			sumTime=max(0, sumTime-dif);
			cout<< time[i].first;
			if(i!=d-1)cout<<" ";
		}cout<<"\n";
	}
}
