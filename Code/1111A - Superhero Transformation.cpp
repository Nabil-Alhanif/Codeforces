#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	if (s.size()!=t.size()) return cout<<"No\n",0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
			if (t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u')continue;
			else return cout<<"No\n",0;
		} else {
			if (t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u')return cout<<"No\n",0;
			else continue;
		}
	}
	cout<<"Yes\n";
}
