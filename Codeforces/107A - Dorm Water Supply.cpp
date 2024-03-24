#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll h,p;
    cin>>h>>p;
    vector<ll>inPipe(h+1),outPipe(h+1);
    map<pair<ll,ll>,ll>pipeSize;
    for (int i=0;i<p;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        outPipe[a]=b;
        inPipe[b]=a;
        pipeSize[{a,b}]=c;
    }
    vector<ll>inHouse,outHouse;
    for (int i=1;i<=h;i++)
    {
        if (!inPipe[i]&&outPipe[i])
            outHouse.push_back(i);
        if (!outPipe[i]&&inPipe[i])
            inHouse.push_back(i);
    }
    cout<<inHouse.size()<<"\n";
    for (auto i:outHouse)
    {
        ll curHouse=i;
        ll curSize=INT_MAX;
        while(outPipe[curHouse])
        {
            curHouse=outPipe[curHouse];
            curSize=min(curSize,pipeSize[{inPipe[curHouse],curHouse}]);
        }
        cout<<i<<" "<<curHouse<<" "<<curSize<<"\n";
    }
}