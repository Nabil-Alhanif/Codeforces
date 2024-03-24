#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, ans = inf;
        cin >> n >> m;
        pair<ll, ll> apps[n];
        vector<ll> satu, dua;
        ll satuSize = 0, duaSize = 0;
        for (int i=0; i<n; i++)
            cin >> apps[i].second;
        for (int i=0; i<n; i++)
            cin >> apps[i].first;
        for (int i=0; i<n; i++)
        {
            if (apps[i].first==1)
            {
                satu.push_back(apps[i].second);
                satuSize++;
            }
            else
            {
                dua.push_back(apps[i].second);
                duaSize++;
            }
        }
        sort(satu.rbegin(), satu.rend());
        sort(dua.rbegin(), dua.rend());
        ll satuSum = 0, duaSum = accumulate(dua.begin(), dua.end(), 0ll);
        /*
        for (auto i:satu)
            cout << i << " ";
        cout << "\n";
        for (auto i:dua)
            cout << i << " ";
        cout << "\n";
        */
        for (int i=0; i<=satuSize; i++)
        {
            while (duaSize>0 && satuSum+duaSum-dua[duaSize-1]>=m)
            {
                duaSize--;
                duaSum -= dua[duaSize];
            }
            if (satuSum+duaSum>=m)
                ans = min(ans, 2*duaSize+i);
            if (i!=satuSize)
                satuSum += satu[i];
        }
        if (ans == inf)
            ans = -1;
        cout << ans << "\n";
    }
}