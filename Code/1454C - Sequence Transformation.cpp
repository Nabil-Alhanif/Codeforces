#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,ans=INT_MAX;
        cin>>n;
        int ar[n];
        vector<int>fin;
        for (int i=0;i<n;i++)
            cin>>ar[i];
        int cur=ar[0];
        for (int i=0;i<n;i++)
        {
            if (ar[i]!=cur)
            {
                fin.push_back(cur);
                cur=ar[i];
            }
        }
        fin.push_back(cur);
        int size=fin.size();
        map<int,vector<int>>pos;
        for (int i=0;i<size;i++)
            pos[fin[i]].push_back(i);
        for (auto i:pos)
        {
            int curSize = i.second.size();
            int curAns = curSize-1;
            if (i.second[0]!=0)
                curAns++;
            if (i.second[curSize-1]!=size-1)
                curAns++;
            //cout<<curAns<<" curAns\n";
            ans=min(ans,curAns);
        }
        cout<<ans<<"\n";
    }
}