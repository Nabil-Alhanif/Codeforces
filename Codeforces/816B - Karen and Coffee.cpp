#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> temperature(200005),pref(200005);
    while (n--)
    {
        ll l,r;
        cin>>l>>r;
        temperature[l]++;
        temperature[r+1]--;
    }
    for (int i=1;i<200005;i++)
        temperature[i]+=temperature[i-1];
    for (int i=1;i<200005;i++)
    {
        pref[i]=pref[i-1];
        if (temperature[i]>=k)
            pref[i]++;
    }
    /*
    for (int i=90;i<=100;i++)
    {
        cout<<temperature[i]<<" "<<pref[i]<<"\n";
    }
    */
    while (q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<"\n";
    }
}