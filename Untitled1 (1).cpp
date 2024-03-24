#include<bits/stdc++.h>
using namespace std;
#define int long long
#define point pair<int,int>
#define x first
#define y second

int n, d = 1e18;
vector<point> s;

bool compy(point a, point b){
	return a.y < b.y;
}

int sq(int x){
	return x*x;
}

int dist(point a, point b){
	return sq(a.x-b.x)+sq(a.y-b.y);
}

void rec(int l, int r){
	if(r-l == 1)return; 
	int mid = (l+r)/2, midx = s[mid].x;
	rec(l, mid); rec(mid, r);
	inplace_merge(s.begin() + l, s.begin() + mid, s.begin() + r, compy);
	vector<point> strip;
	for(int i = l; i < r; i++)
		if(sq(s[i].x - midx) < d)
			strip.push_back(s[i]);
	//cout << l << ' ' << r << " : ";for(auto i:strip)cout << "(" << i.x << ' ' << i.y << ") ";cout << '\n';
	for(int i = 0, j = 0; i < strip.size(); i++){
		while(j < i && sq(strip[i].y - strip[j].y) > d)
			j++;
		for(int k = j; k < i; k++)
			d = min(d, dist(strip[k], strip[i]));
	} 
	return;
}

main(){
	cin >> n;
	s.resize(n);
	for(int i = 0; i < n; i++)
		cin >> s[i].x >> s[i].y;
	sort(s.begin(), s.end());
	rec(0, n);
	cout << d << '\n';
}
