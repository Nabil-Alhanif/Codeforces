#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int size=s.size(), pos=s.size();
	for (string::iterator i=s.begin();i!=s.end();++i)
	{
		if (!(*i%2))
		{
			pos=i-s.begin();
			if (s[s.size()-1]>*i)break;
		}
	}
	if(s.size()==pos)return cout<<"-1\n",0;
	swap(s[pos],s[s.size()-1]);
	cout<<s<<"\n";
}
