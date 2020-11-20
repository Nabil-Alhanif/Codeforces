#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,w;
        cin>>n>>w;
        ll ww=(w/2)+(w%2);
        //cout<<"ww "<<ww<<"\n";
        vector<pair<ll,int>>knapsack(n+1);
        knapsack[0].second=-1;
        for (int i=1;i<=n;i++)
        {
            cin>>knapsack[i].first;
            knapsack[i].second=i;
        }
        sort(knapsack.begin(),knapsack.end());
        ll cur=0;
        vector<ll>ans;
        for (int i=1;i<=n;i++)
        {
            if (knapsack[i].first>=ww&&knapsack[i].first<=w)
            {
                ans.clear();
                ans.push_back(knapsack[i].second);
                cur=knapsack[i].first;
                break;
            }
            cur+=knapsack[i].first;
            ans.push_back(knapsack[i].second);
            if (cur>w)
            {
                //cout<<"Too heavy.\n";
                cur=0;
                break;
            }
            if (cur>=ww)
            {
                //cout<<cur<<" cur\n";
                break;
            }
        }
        if (cur<ww)
        {
            //cout<<"Too light.\n";
            cur=0;
        }
        if (cur==0)
            cout<<"-1";
        else
        {
            cout<<ans.size()<<"\n";
            for (auto i:ans)
                cout<<i<<" ";
        }
        cout<<"\n";
    }
}