//ok, jadi Nabil lagi mainan pair. Awalnya mau pointer sekalian, tapi error.
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,pair<int,pair<int,int> > >m;
	vector<string> name;
	vector<pair<pair<int,pair<int,int> >,string > > finScore;
	//vector<pair<pair<int,pair<int,int> >,string > >::iterator it;
	for (int i=0;i<n;i++)
	{
		string team;
		cin>>team;
		//name.push_back(team);
	}
	int tmp=n*(n-1)/2;
	for (int i=0;i<tmp;i++)
	{
		string s;
		cin>>s;
		int sa,sb,pos=s.find("-");
		scanf("%d:%d",&sa,&sb);
		string ta=s.substr(0,pos),tb=s.substr(pos+1,s.size()-pos-1);
		if (sa==sb)
		{
			m[ta]={m[ta].first+1,{m[ta].second.first+sb,m[ta].second.second+sa}};
			m[tb]={m[tb].first+1,{m[tb].second.first+sa,m[tb].second.second+sb}};
		}
		if (sa>sb)
		{
			m[ta]={m[ta].first+3,{m[ta].second.first+sb,m[ta].second.second+sa}};
			m[tb]={m[tb].first+0,{m[tb].second.first+sa,m[tb].second.second+sb}};
		}
		if (sb>sa)
		{
			m[ta]={m[ta].first+0,{m[ta].second.first+sb,m[ta].second.second+sa}};
			m[tb]={m[tb].first+3,{m[tb].second.first+sa,m[tb].second.second+sb}};
		}
		//cout<<ta<<" "<<tb<<" "<<pos<<" "<<sa<<" "<<sb<<"\n";
	}
	for (auto i:m)
	{
		//cout<<i.first<<" "<<i.second.first<<" "<<i.second.second.first<<" "<<i.second.second.second<<"\n";
		finScore.push_back({{i.second.first,{i.second.second.second-i.second.second.first,i.second.second.second}},i.first});
	}
	sort(finScore.begin(),finScore.end());
	/*for debugging
	for (auto i:finScore)
	{
		cout<<i.second<<" "<<i.first.first<<" "<<i.first.second.first<<" "<<i.first.second.second<<"\n";
	}*/
	int c=0;
	for (int i=finScore.size()-1;c<n/2;i--)
	{
		name.push_back(finScore[i].second);
		c++;
	}
	sort(name.begin(),name.end());
	for (auto i:name)cout<<i<<"\n";
}
