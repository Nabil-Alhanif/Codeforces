#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>pos,poss;
    for (int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        pos[tmp]=i+n;
    }
    for (int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        int dif = (pos[tmp]-i)%n;
        poss[dif]++;
    }
    int ans=1;
    for (auto i:poss)
        ans=max(ans,i.second);
    cout<<ans<<"\n";
}