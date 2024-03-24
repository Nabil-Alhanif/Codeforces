#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<ll> defeat(n+1);
    set<ll> participant;
    set<ll>::iterator itl, itu;
    for (int i=1; i<=n; i++)
        participant.insert(i);
    while (m--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        itl = participant.lower_bound(l);
        itu = participant.upper_bound(r);
        for (set<ll>::iterator it=itl; it!=itu; it++)
            defeat[*it] = x;
        participant.erase(itl, itu);
        if (participant.size())
            participant.insert(--itu, x);
        else participant.insert(x);
    }
    for (int i=1; i<=n; i++)
        if (defeat[i]!=i)
            cout << defeat[i] << ' ';
        else cout << "0 ";
    cout<<"\n";
}