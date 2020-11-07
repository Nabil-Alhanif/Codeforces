#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> >m;
bool visit[100005];
int main()
{
	int n, ma;
	cin>>n>>ma;
	while (ma--)
	{
		int i, j;
		cin>>i>>j;
		m[i].push_back(j);
		m[j].push_back(i);
	}
	visit[1]=1;
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(1);
	while (!pq.empty())
	{
		int cur=pq.top();
		pq.pop();
		cout<<cur<<" ";
		for (auto i:m[cur])
		{
			if (!visit[i])
			{
				pq.push(i);
				visit[i]=1;
			}
		}
	}
	cout<<"\n";
}
