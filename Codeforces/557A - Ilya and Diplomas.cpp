#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll stu;
	cin >> stu;
	ll a1, a2, b1, b2, c1, c2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	cin >> c1 >> c2;
	ll a=a1, b=b1,c=c1;
	stu-=a1;
	stu-=b1;
	stu-=c1;
	ll t=min(stu, a2-a1);
	stu-=t;
	a+=t;
	t = min(stu, b2-b1);
	stu-=t;
	b+=t;
	t=min(stu,c2-c1);
	stu-=t;
	c+=t;
	cout <<a<<" "<<b<<" "<<c<<"\n";
}
