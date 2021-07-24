#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll s, b;
    cin >> s >> b;

    vector<ll> spaceship(s);
    for (auto &i:spaceship)
        cin >> i;

    vector<pair<ll, ll>> base(b);
    for (auto &i:base)
        cin >> i.first >> i.second;
    sort(base.begin(), base.end());

    for (int i = 1; i < b; i++)
        base[i].second += base[i-1].second;

    for (auto i:spaceship)
    {
        int l = 0, r = b - 1, mid, pos = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            
            if (base[mid].first <= i)
            {
                pos = mid;
                l = mid + 1;
            }

            else r = mid - 1;
        }

        // cout << i << " " << pos << "\n";
        if (pos == -1)
            cout << "0 ";
        else cout << base[pos].second << " ";
    }
    cout << "\n";
}
