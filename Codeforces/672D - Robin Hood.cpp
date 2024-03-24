#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, total = 0;
    cin >> n >> k;

    ll person[n];
    for (int i = 0; i < n; i++)
    {
        cin >> person[i];
        total += person[i];
    }

    sort(person, person + n);
    
    ll mins, maks;

    ll l = 0, r = total/n, mid;
    while (l != r)
    {
        mid = ((l + r) / 2) + 1;
        ll needed_days = 0;
        for (int i = 0; i < n; i++)
        {
            if (person[i] < mid)
                needed_days += mid - person[i];
        }
        if (needed_days > k)
            r = mid-1;
        else l = mid;
    }
    mins = l;

    l = (total + n - 1)/n, r = person[n-1];
    while (l != r)
    {
        mid = (l + r) / 2;
        ll needed_days = 0;
        for (int i = 0; i < n; i++)
        {
            if (person[i] > mid)
                needed_days += person[i] - mid;
        }
        if (needed_days > k)
            l = mid + 1;
        else r = mid;
    }
    maks = l;

    cout << maks - mins << "\n";
}
