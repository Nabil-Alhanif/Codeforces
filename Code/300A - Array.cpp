#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ca=0,cb=0;
	cin>>n;
	int ar[n];
	vector<int>va,vb,vc;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]<0)ca++;
		if(ar[i]>0)cb++;
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i++)
	{
		if (ar[i]<0)
		{
			if (va.empty()){
				va.push_back(ar[i]);
				ca--;
			}
			else {
				if(ca%2)
				{
					ca--;
					vb.push_back(ar[i]);
				} else vc.push_back(ar[i]);
			}
		} else {
			if (ar[i]==0)vb.push_back(ar[i]);
			else vc.push_back(ar[i]);
		}
	}
	cout<<va.size();
	for (auto i:va)cout<<" "<<i;cout<<"\n";
	cout<<vc.size();
	for(auto i:vc)cout<<" "<<i;cout<<"\n";
	cout<<vb.size();
	for (auto i:vb)cout<<" "<<i;cout<<"\n";
}
