#include <bits/stdc++.h>
using namespace std;
vector<int>ans,color;
map<int,vector<int>>tree;
void dfs(int n, int p)
{
    for (auto i:tree[n])
    {
        if (i!=p)
        {
            color[i]*=-1;
            ans.push_back(i);
            dfs(i,n);
            color[n]*=-1;
            ans.push_back(n);
            if (color[i]!=1)
            {
                ans.push_back(i);
                ans.push_back(n);
                color[i]=1;
                color[n]*=-1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    color.resize(n+1);
    for (int i=0;i<n;i++)
        cin>>color[i+1];
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans.push_back(1);
    dfs(1,0);
    if (color[1]!=1)
    {
        ans.push_back(tree[1][0]);
        ans.push_back(1);
        ans.push_back(tree[1][0]);
    }
    for (auto i:ans)
        cout<<i<<" ";
    cout<<"\n";
}