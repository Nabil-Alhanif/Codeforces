#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int a,b;
		string s1,s2;
		cin>>s1>>s2;
		a=s1.size();b=s2.size();
		sort(s1.begin(),s1.end());
		bool findd=0;
		for (int i=0;i+a<=b;i++)
		{
			string tmp=s2.substr(i,a);
			sort(tmp.begin(),tmp.end());
			//cout<<s1<<" "<<tmp<<" cuk!!\n";
			//cout<<(tmp==s1)<<"\n";
			findd=(findd||tmp==s1);
		}
		cout<<(findd?"YES\n":"NO\n");
	}
}
