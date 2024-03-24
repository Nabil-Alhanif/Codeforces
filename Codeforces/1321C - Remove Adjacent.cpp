#include <bits/stdc++.h>
using namespace std;
int main()
{
	int size;string s;
	cin>>size>>s;
	for (char c='z';c>='a';c--)
	{
		for (int i=0;i<s.size();i++)
		{
			if (s[i]==c&&(s[i-1]==c-1||s[i+1]==c-1))
			{
				s.erase(i,1);
				i=-1;
			}
		}
	}
	//cout<<s<<"\n";
	cout<<size-s.size()<<"\n";
}
