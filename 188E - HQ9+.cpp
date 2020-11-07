#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for (auto i:s)
	{
		if (i=='H'||i=='Q'||i=='9')return cout<<"YES\n",0;
	}cout<<"NO\n";
}
