#include<bits/stdc++.h>
using namespace std;
struct unyep{
	string melati;
	int woy=0,lah=0;
	void clear()
	{
		woy=0;lah=0;
		melati.clear();
	}
};
int main()
{
	vector<unyep> v;
	int n;string s;
	cin>>n>>s;
	unyep penyu;
	int size=s.size();
	for (int i=0;i<size;i++)
	{
		if (i==size-1)
		{
			if(s[i]=='1')
			{
				if(penyu.woy+1==penyu.lah)
				{
					v.push_back(penyu);
					penyu.clear();
				}
			} else {
				if (penyu.lah+1==penyu.woy)
				{
					v.push_back(penyu);
					penyu.clear();
				}
			}
		}
		penyu.melati+=s[i];
		if(s[i]=='1')penyu.woy++;
		else penyu.lah++;
	}
	v.push_back(penyu);
	cout<<v.size()<<"\n";
	for (auto i:v)
	{
		cout<<i.melati<<" ";
	}
}
