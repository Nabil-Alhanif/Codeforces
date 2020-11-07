#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for (string::iterator it=s.begin()+1;it!=s.end();it++)
	{
		if (*it!='0') return cout<<(s.size()-1)/2+1<<"\n",0;
	}
	cout<<s.size()/2<<"\n";
}
