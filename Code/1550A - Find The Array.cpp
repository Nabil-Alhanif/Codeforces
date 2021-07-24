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
        int s, ans = 0, tot = 0;
        cin >> s;

        for (int i = 1; tot != s; i += 2)
        {
            if (tot + i > s)
            {
                ans++;
                break;
            }
            
            tot += i;
            ans++;
        }

        cout << ans << "\n";
    }
}
