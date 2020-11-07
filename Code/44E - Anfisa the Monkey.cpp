#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k,a,b;string s;
  cin>>k>>a>>b>>s;
  int size=s.size();
  if (size<k*a||size>k*b)
    return cout<<"No solution\n",0;
  vector<int>v;
  for (int i=0;i<k;i++)
    v.push_back(a);
  size-=k*a;
  for (auto&i:v)
  {
    int tmp=min(b-a,size);
    size-=tmp;
    i+=tmp;
  }
  int point=0;
  for (auto i:v)
  {
    while (i--)
    {
      cout<<s[point];
      point++;
    }cout<<"\n";
  }
}
