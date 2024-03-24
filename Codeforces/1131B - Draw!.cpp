#include <bits/stdc++.h>
using namespace std;
int main() {
	int a=0, b=0, n,ans=1;
	cin >> n;
	while (n--) {
		int t1, t2;
		cin >> t1 >> t2;
		t1-=a, t2-=b;
		//cout <<t1<<" "<<t2<<"\n";
		if (a==b) {
			int dif = min(t1, t2);
			ans+=dif;
			a+=t1;
			b+=t2;
			//cout << "asd"<<a<<" "<<b<<" "<<ans<<"\n";
		} else if(a<b) {
			int dif = b-a;
			a+=min(t1, dif);
			t1=max(0, t1-dif);
			if (a==b) {
				ans++;
				dif = min(t1, t2);
				ans+=dif;
				a+=t1;
				b+=t2;
			} else {
				a+=t1;
				b+=t2;
			}
			//cout<<"asdsad"<<a<<" "<<b<<" "<<ans<<"\n";
		} else {
			int dif = a-b;
			b+=min(dif, t2);
			t2=max(0, t2-dif);
			if (a==b) {
				ans++;
				dif = min(t1, t2);
				ans+=dif;
				a+=t1;
				b+=t2;
			} else {
				a+=t1;
				b+=t2;
			}
			//cout<<"sadsd"<<a<<" "<<b<<" "<<ans<<"\n";
		}
	}
	cout<<ans<<"\n";
}
