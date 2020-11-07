#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		string name;int s,e;
		cin>>name>>s>>e;
		if (s>=2400&&e>s)return cout<<"YES\n",0;
	}
	cout<<"NO\n";
}
