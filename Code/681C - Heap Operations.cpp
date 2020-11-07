#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	ll n;
	cin>>n;
	priority_queue<ll, vector<ll>, greater<ll> > q;
	vector<pair<string,ll> > ans;
	while (n--)
	{
		string s;ll x=0;
		cin>>s;
		if (s!="removeMin")
			cin>>x;
		if (s=="insert")
			q.push(x);
		if (s=="getMin")
		{
			bool find=0;
			while (!q.empty())
			{
				//cout<<q.top()<<" "<<x<<" search\n";
				if (q.top()>=x)
				{
					if (q.top()==x)
						find=1;
					break;
				}
				q.pop();
				ans.push_back({"removeMin",1});
				//ans.push_back({"size",q.size()});
			}
			if (!find)
			{
				q.push(x);
				ans.push_back({"insert",x});
				//ans.push_back({"size",q.size()});
			}
		}
		if (s=="removeMin")
		{
			if (q.empty())
			{
				ans.push_back({"insert",1});
				//ans.push_back({"size",q.size()+1});
			}
			else q.pop();
		}
		ans.push_back({s,x});
		//ans.push_back({"size",q.size()});
	}
	cout<<ans.size()<<"\n";
	for (auto i:ans)
	{
		cout<<i.first;
		if (i.first!="removeMin")
			cout<<" "<<i.second;
		cout<<"\n";
	}
}
