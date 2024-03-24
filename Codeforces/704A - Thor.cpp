#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,lastDel=0,m=1;
    cin>>n>>q;
    vector<int>msg[n+1];
    set<int>finMsg;
    while (q--)
    {
        int i,x;
        cin>>i>>x;
        if (i==1)
        {
            msg[x].push_back(m);
            finMsg.insert(m);
            m++;
        } else if (i==2)
        {
            for (auto j:msg[x])
                finMsg.erase(j);
            msg[x].clear();
        } else if (i==3)
        {
            while(!finMsg.empty()&&*finMsg.begin()<=x)
                finMsg.erase(finMsg.begin());
        }
        cout<<finMsg.size()<<"\n";
    }
}