#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int letter[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	inline void operator+=(const node&l)
	{
		for (int i=0;i<17;i++)
		{
			this->letter[i]+=l.letter[i];
		}
	}
	
	inline node operator+(const node&l)
	{
		node ret;
		for (int i=0;i<17;i++)
		{
			ret.letter[i]=this->letter[i]+l.letter[i];
		}
		return ret;
	}
	
	inline node operator-(const node&l)
	{
		node ret;
		for (int i=0;i<17;i++)
		{
			ret.letter[i]=this->letter[i]-l.letter[i];
		}
		return ret;
	}
};

inline int change(string s, char search, int i, int size, vector<node>ar, int cae=0)
{
	if (size==1)
	{
		int data=0;
		if (search!=s[i])data=1;
		//cout<<search<<" size: "<<size<<" case: "<<cae<<" index: "<<i<<" data: "<<data<<"\n";
		return data;
	}
	int nMove=size/2;
	int tmp1=nMove-(ar[i+nMove].letter[search-'a']-ar[i].letter[search-'a']);
	int tmp2=nMove-(ar[i+size].letter[search-'a']-ar[i+nMove].letter[search-'a']);
	//cout<<search<<" size: "<<size<<" case: "<<cae<<" tmp1 data: "<<i<<" "<<i+nMove<<" "<<tmp1<<" tmp2 data: "<<i+nMove<<" "<<i+size<<" "<<tmp2<<"\n";
	int ans=0;
	if (tmp1<=tmp2)
		ans=tmp1+change(s,search+1,i+nMove,nMove,ar,1);
	else ans=tmp2+change(s,search+1,i,nMove,ar,2);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int size;string s;
		cin>>size>>s;
		vector<node>ar(size+1);
		for (int i=1;i<=size;i++)
		{
			ar[i].letter[s[i-1]-'a']=1;
			ar[i]+=ar[i-1];
		}
		/*
		cout<<ar[3].letter[2]-ar[2].letter[2]<<"\n";
		for (int i=1;i<=size;i++)
		{
			node tmp=ar[i]-ar[0];
			for (int i=0;i<17;i++)
				cout<<tmp.letter[i]<<" ";
			cout<<"\n";
		}
		*/
		long long ans=change(s,'a',0,size,ar);
		cout<<ans<<"\n";
	}
}

