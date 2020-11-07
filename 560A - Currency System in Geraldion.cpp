#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	bool ada=0;
	while (n--)
	{
		int ai;
		cin>>ai;
		if(ai==1)ada=1;
	}
	if(ada)cout<<"-1\n";
	else cout<<"1\n";
}
