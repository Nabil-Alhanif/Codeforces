#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>path(n+1);
    vector<bool>visit(n+1);
    path[1].push_back(1);
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    queue<pair<int,pair<double,double>>>went;
    went.push({1,{1,0}});
    visit[1]=1;
    visit[0]=1;
    double ans=0.0;
    while (!went.empty())
    {
        int curNode=went.front().first;
        double curProb=went.front().second.first;
        double curPath=went.front().second.second;
        went.pop();
        double size=path[curNode].size()-1;
        bool end=1;
        for (auto i:path[curNode])
        {
            if (!visit[i])
            {
                //cout<<i<<" "<<size<<" "<<curProb<<"\n";
                visit[i]=1;
                went.push({i,{size*curProb,curPath+1}});
                end=0;
            }
        }
        curPath/=curProb;
        if (end)
            //cout<<ans<<" "<<curPath<<"\n";
            ans+=curPath;
    }
    //cout<<curTot<<" "<<curNum<<"\n";
    cout<<fixed<<setprecision(12)<<ans<<"\n";
}