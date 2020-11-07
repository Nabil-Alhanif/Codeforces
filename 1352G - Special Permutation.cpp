#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		deque<int>dq;
		if(n<4)
		{
			cout<<"-1\n";
			continue;
		}
		dq.push_back(3);
		dq.push_back(1);
		dq.push_back(4);
		dq.push_back(2);
		for (int i=5;i<=n;i++)
		{
			if (i%2)dq.push_front(i);
			else dq.push_back(i);
		}
		while (!dq.empty())
		{
			cout<<dq.front()<<" ";
			dq.pop_front();
		}
		cout<<"\n";
	}
}
