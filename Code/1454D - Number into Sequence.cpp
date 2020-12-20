#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,maxFact=0;
        cin>>n;
        map<ll,ll>fact;
        vector<ll>ans;
        for (ll i=2;i*i<=n;i++)
        {
            while (!(n%i))
            {
                fact[i]++;
                n/=i;
            }
            maxFact=max(maxFact,fact[i]);
        }
        if (n>1)
        {
            fact[n]++;
            maxFact=max(maxFact,fact[n]);
        }
        /*
        for (auto &i:fact)
            cout<<i.first<<" "<<i.second<<"\n";
        cout<<"\n";
        */
        for (int i=0;i<maxFact;++i)
        {
            ll ret=1;
            for (auto &j:fact)
            {
                if (j.second)
                {
                    ret*=j.first;
                    j.second--;
                }
            }
            ans.push_back(ret);
        }
        cout<<maxFact<<"\n";
        for (auto it=ans.rbegin();it!=ans.rend();++it)
            cout<<*it<<" ";
        cout<<"\n";
    }
}