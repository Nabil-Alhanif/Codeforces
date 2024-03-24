#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n;
  map<int,int>m;
  vector<int>v;
  cin>>n;
  for (int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    if (!m[tmp])
      v.push_back(tmp);
    m[tmp]++;
  }
  sort(v.begin(),v.end(),greater<int>());
  int ans=m[v[0]];
  for (auto i:v)
  {
    if (m[i]>ans)
    {
      ans=m[i];
    }
  }
  cout<<ans<<"\n";
}
