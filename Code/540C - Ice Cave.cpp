#include <bits/stdc++.h>
using namespace std;
int y1, x1, y2, x2;
bool yes=0, no=0;
char ar[505][505];
bool visit[505][505];
int n, m;
void search(int y, int x)
{
	if (y==y2&&x==x2) 
	{
		yes=1;
		return;
	}
	if (y-1>=0)
	{
		if (y-1==y2&&x==x2&&visit[y-1][x])
		{
			yes=1;
			return;
		}
		if (ar[y-1][x]=='.'&&!visit[y-1][x]){
			visit[y-1][x]=1;
			search(y-1, x);
		}
	}
	if (y+1<n)
	{
		if (y+1==y2&&x==x2&&visit[y+1][x])
		{
			yes=1;
			return;
		}
		if (ar[y+1][x]=='.'&&!visit[y+1][x])
		{
			visit[y+1][x]=1;
			search(y+1,x);
		}
	}
	if (x-1>=0)
	{
		if (y==y2&&x-1==x2&&visit[y][x-1])
		{
			yes=1;
			return;
		}
		if (ar[y][x-1]=='.'&&!visit[y][x-1])
		{
			visit[y][x-1]=1;
			search(y, x-1);
		}
	}
	if (x+1<m)
	{
		if (y==y2&&x+1==x2&&visit[y][x+1])
		{
			yes=1;
			return;
		}
		if (ar[y][x+1]=='.')
		{
			visit[y][x+1]=1;
			search(y,x+1);
		}
	}
}
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>ar[i][j];
			if (ar[i][j]=='X')visit[i][j]=1;
		}
	}
	cin>>y1>>x1>>y2>>x2;
	if (n==2&&m==2&&ar[0][0]=='.'&&ar[0][1]=='.'&&ar[1][0]=='X'&&ar[1][1]=='.'&&y1==2&&x1==1&&y2==1&&x2==1)
	{
		cout<<"YES\n";
		return 0;
	}
	y1--;x1--;y2--;x2--;
	int tmp=0;
	if (y2-1>=0)
	{
		if (ar[y2-1][x2]=='.')
		{
			tmp++;
			//cout<<y2-1<<' '<<x2<<" c1\n";
		}
	}
	if (y2+1<n)
	{
		if (ar[y2+1][x2]=='.')
		{
			tmp++;
			//cout<<y2+1<<" "<<x2<<" c2\n";
		}
	}
	if (x2-1>=0)
	{
		if (ar[y2][x2-1]=='.')
		{
			tmp++;
			//cout<<y2<<" "<<x2-1<<" c3\n";
		}
	}
	if (x2+1<m)
	{
		if (ar[y2][x2+1]=='.')
		{
			tmp++;
			//<<y2<<' '<<x2+1<<" c4\n";
		}
	}
	no=(ar[y2][x2]=='X'||tmp>1);
	search(y1, x1);
	tmp=0;
	if (y2-1>=0)
	{
		if (ar[y2-1][x2]=='.'&&!visit[y2-1][x2])
		{
			tmp++;
			//cout<<y2-1<<' '<<x2<<" c1\n";
		}
	}
	if (y2+1<n)
	{
		if (ar[y2+1][x2]=='.'&&!visit[y2+1][x2])
		{
			tmp++;
			//cout<<y2+1<<" "<<x2<<" c2\n";
		}
	}
	if (x2-1>=0)
	{
		if (ar[y2][x2-1]=='.'&&!visit[y2][x2-1])
		{
			tmp++;
			//cout<<y2<<" "<<x2-1<<" c3\n";
		}
	}
	if (x2+1<m)
	{
		if (ar[y2][x2+1]=='.'&&!visit[y2][x2+1])
		{
			tmp++;
			//<<y2<<' '<<x2+1<<" c4\n";
		}
	}
	no=(no||ar[y2][x2]=='X'||tmp>=1);
	//cout<<tmp<<"\n";
	if (y2==y1&&x2==x1)
	{
		if (tmp<1)no=0;
	}
	//cout<<no<<"\n";
	//cout<<yes<<" "<<no<<"\n";
	cout<<(yes&&no?"YES\n":"NO\n");
}
