#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if (s.find('0')!=string::npos)
	{
		int pos=s.find('0');
		cout<<s.substr(0,pos)<<s.substr(pos+1,s.size()-pos)<<"\n";
		return 0;
	} else {
		int si=s.size();
		cout<<s.substr(0,s.size()-1)<<"\n";
	}
}
