#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=1;
    map<string,vector<string>>repost;
    cin>>n;
    while (n--)
    {
        string n2,s,n1;
        cin>>n2>>s>>n1;
        //cout<<n2<<" "<<n1<<"\n";
        transform(n1.begin(),n1.end(),n1.begin(),::tolower);
        transform(n2.begin(),n2.end(),n2.begin(),::tolower);
        repost[n1].push_back(n2);
    }
    stack<pair<string,int>>s;
    s.push({"polycarp",1});
    while (!s.empty())
    {
        string lastName=s.top().first;
        int last=s.top().second;
        //cout<<"Last name: "<<lastName<<"\n";
        ans=max(ans,last);
        s.pop();
        for (auto i:repost[lastName])
            s.push({i,last+1});
    }
    cout<<ans<<"\n";
}