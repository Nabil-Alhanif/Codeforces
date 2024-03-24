#include <bits/stdc++.h>
using namespace std;

bool benar;
int a, b, sx, sy;
char ar[50][50], c;
bool visit[50][50];
void dfs(int x, int y, int move) {
	if (x < 0||x > a||y < 0|| y > b) {
		return;
	}
	if (visit[x][y]==true&&x==sx&&y==sy&&move>4) {
		benar=true;
	}
	if (visit[x][y]==false&&ar[x][y]==c) {
		visit[x][y]=true;
		dfs(x+1, y, move+1);
		dfs(x-1, y, move+1);
		dfs(x, y+1, move+1);
		dfs(x, y-1, move+1);	
	}
	
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0;j < b; j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			memset(visit, false, sizeof(visit));
			c= ar[i][j];
			sx = i;
			sy = j;
			dfs(i, j, 1);
		}
	}
	if (benar) cout << "Yes\n";
	else cout << "No\n";
}
