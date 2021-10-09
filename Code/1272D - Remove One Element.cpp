#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, ans = 0;
    cin >> n;

    vector<int> ar(n), pref(n, 1), suff(n, 1);

    for (auto &i:ar)
        cin >> i;

    for (int i = 1; i < n; i++)
    {
        if (ar[i - 1] < ar[i])
            pref[i] = pref[i - 1] + 1;
        ans = max(ans, pref[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ar[i + 1] > ar[i])
            suff[i] = suff[i + 1] + 1;
        ans = max(ans, suff[i]);
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (ar[i] < ar[i + 2])
            ans = max(ans, pref[i] + suff[i + 2]);
    }

    cout << ans << "\n";
}
