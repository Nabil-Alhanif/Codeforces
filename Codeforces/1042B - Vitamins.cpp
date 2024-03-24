#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a,b,c,ab,bc,ac,abc;
	while (n--)
	{
		int ci;string si;
		cin>>ci>>si;
		bool aa=(si.find('A')!=string::npos),bb=(si.find('B')!=string::npos),cc=(si.find('C')!=string::npos);
		//cout<<si<<" "<<aa<<" "<<bb<<" "<<cc<<"\n";
		if (aa)a.push_back(ci);
		if (bb)b.push_back(ci);
		if (cc)c.push_back(ci);
		if (aa&&bb)ab.push_back(ci);
		if (aa&&cc)ac.push_back(ci);
		if (bb&&cc)bc.push_back(ci);
		if (aa&&bb&&cc)abc.push_back(ci);
	}
	if (!a.size()||!b.size()||!c.size())
	{
		cout<<"-1\n";
		return 0;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	ab.push_back(a[0]+b[0]);
	ac.push_back(a[0]+c[0]);
	bc.push_back(b[0]+c[0]);
	sort(ab.begin(),ab.end());
	sort(ac.begin(),ac.end());
	sort(bc.begin(),bc.end());
	abc.push_back(ab[0]+bc[0]);
	abc.push_back(ab[0]+ac[0]);
	abc.push_back(ac[0]+bc[0]);
	abc.push_back(a[0]+bc[0]);
	abc.push_back(b[0]+ac[0]);
	abc.push_back(c[0]+ab[0]);
	abc.push_back(a[0]+b[0]+c[0]);
	sort(abc.begin(),abc.end());
	cout<<abc[0]<<"\n";
}
