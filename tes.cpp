#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e13, MOD = 1e9+7;

int ans = 0;
map<vector<int>, int>ans2;

void rek(int i, int pos)
{
    cout << i << " " << pos << "\n";
    if (i<=9 && pos==7)
    {
        ans++;
        return;
    }
    for (int j=i+1; j<=9; j++)
        rek(j, pos+1);
}

bool pal(string s)
{
    int size = s.size();
    for (int i=0, j=size-1; i<=j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

void cek(vector<int>v, int jum)
{
  if (jum==4)
  {
    for (int i=0; i<4; i++)
    {
      if (v[i]==i)
        return;
    }
    ans++;
    ans2[v]++;
    return;
  }
  for (int i=0; i<4; i++)
  {
    vector<int> v2 = v;
    if (i!=jum && v[i]==-1)
    {
      v2[i]=jum;
      cek(v2, jum+1);
    }
  }
}

int main()
{
  for (int i=0;i<=20;i++)
  {
    if (i*30+(20-i)*20<=500)
      ans = max(ans, i*5+(20-i)*3);
  }
  cout << ans << "\n";
}
