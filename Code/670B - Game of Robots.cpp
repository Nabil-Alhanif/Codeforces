#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> robot(n);
    for (int i = 0; i < n; i++)
    {
        cin >> robot[i].first;
        robot[i].second = i+1;
        
        if (i)
            robot[i].second += robot[i-1].second;
    }

    int l = 0, r = n-1, mid, pos;
    while (l <= r)
    {
        mid = (l+r)/2;
        if (robot[mid].second <= k)
        {
            pos = mid;
            l++;
        }
        else
        {
            r--;
        }
    }
    
    k -= robot[pos].second;
    if (k == 0)
        cout << robot[pos].first << "\n";
    else cout << robot[k-1].first << "\n";
}
