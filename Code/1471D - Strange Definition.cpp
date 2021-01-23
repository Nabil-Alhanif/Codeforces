#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll square(ll n)
{
    for (ll i=sqrt(n);i>0;i--)
    {
        if (!(n%(i*i)))
            return (i*i);
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,prime=0,bisa;
        cin>>n;
        map<ll,ll>m;
        vector<ll>v;
        for (int i=0;i<n;i++)
        {
            ll tmp;
            cin>>tmp;
            ll sqr=square(tmp);
            if (sqr==tmp)
                prime++;
            tmp/=sqr;
            if (!m[tmp])
                v.push_back(tmp);
            m[tmp]++;
        }
        ll maks=0,ganjil=0,su=0;
        for(int i = 0; i < v.size(); i++){
            maks = max(maks, m[v[i]]);
            if(m[v[i]] % 2== 1 && v[i]!= 1)
                ganjil = max(ganjil, m[v[i]]);
            else if(m[v[i]]%2 == 0 && v[i]!= 1)
                su += m[v[i]];
        }
        ll q;
        cin>>q;
        while (q--)
        {
            ll sec;
            cin>>sec;
            if (!(sec))
                cout<<maks<<"\n";
            else
                cout<<max(su+m[1],ganjil)<<"\n";
        }
    }
}