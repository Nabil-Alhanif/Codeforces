#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	int x[n],y[n];
	for (int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	vector<bool>visit(n);
	for (int i=0;i<n;i++)
	{
		if (!visit[i])
		{
			ans++;
			stack<int>s;
			s.push(i);
			while (!s.empty())
			{
				int cur=s.top();
				s.pop();
				visit[cur]=1;
				for (int i=0;i<n;i++)
				{
					if ((x[i]==x[cur]||y[i]==y[cur])&&!visit[i])
						s.push(i);
				}
			}
		}
	}
	cout<<ans-1<<"\n";
}