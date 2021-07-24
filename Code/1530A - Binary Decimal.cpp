#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int ans = 0;
        for (auto i:s)
            ans = max(ans, (i - '0'));
        cout << ans << "\n";
    }
}
