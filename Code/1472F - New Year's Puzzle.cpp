#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        if (m==0)
        {
            cout<<"YES\n";
            continue;
        }
        ll atas=0,bawah=0;
        map<ll,vector<ll>>ma;
        vector<ll>v;
        for (int i=0;i<m;i++)
        {
            ll r,c;
            cin>>r>>c;
            if (r==1)
                atas++;
            else bawah++;
            ma[c].push_back(r);
            if (ma[c].size()==1)
                v.push_back(c);
        }
        ma[0].push_back(1);
        ma[0].push_back(2);
        ma[n+1].push_back(1);
        ma[n+1].push_back(2);
        v.push_back(0);
        v.push_back(n+1);
        sort(v.begin(),v.end());
        int size=v.size();
        bool bisa=1;
        for (int i=0;i<size-1;i++)
        {
            if (ma[v[i]].size()==1)
            {
                if (ma[v[i+1]].size()==2)
                {
                    //cout<<v[i]<<" "<<v[i+1]<<" c1\n";
                    bisa=0;
                    break;
                }
                else
                {
                    if (ma[v[i]][0]==ma[v[i+1]][0])
                    {
                        if (!((v[i+1]-v[i])%2))
                        {
                            //cout<<v[i]<<" "<<v[i+1]<<" c2\n";
                            bisa=0;
                            break;
                        }
                        else
                        {
                            if (ma[v[i+1]][0]==1)
                                ma[v[i+1]].push_back(2);
                            else ma[v[i+1]].push_back(1);
                        }
                    }
                    else
                    {
                        if (((v[i+1]-v[i])%2))
                        {
                            //cout<<v[i]<<" "<<v[i+1]<<" c3\n";
                            bisa=0;
                            break;
                        }
                        else
                        {
                            if (ma[v[i+1]][0]==1)
                                ma[v[i+1]].push_back(2);
                            else ma[v[i+1]].push_back(1);
                        }
                    }
                }
            }
        }
        if (bisa)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}