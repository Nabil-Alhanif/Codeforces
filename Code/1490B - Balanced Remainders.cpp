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
        int n, a;
        cin >> n;

        vector<int> ar(3);
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ar[a%3]++;
        }
        
        int ans = 0;

        if (ar[0] > (n/3))
        {
            ar[1] += ar[0] - (n/3);
            ans += ar[0] - (n/3);
            ar[0] = n/3;
        }

        if (ar[1] > (n/3))
        {
            ar[2] += ar[1] - (n/3);
            ans += ar[1] - (n/3);
            ar[1] = n/3;
        }

        if (ar[2] > (n/3))
        {
            ar[0] += ar[2] - (n/3);
            ans += ar[2] - (n/3);
            ar[2] = n/3;
        }

        if (ar[0] > (n/3))
        {
            ar[1] += ar[0] - (n/3);
            ans += ar[0] - (n/3);
            ar[0] = n/3;
        }

        if (ar[1] > (n/3))
        {
            ar[2] += ar[1] - (n/3);
            ans += ar[1] - (n/3);
            ar[1] = n/3;
        }

        if (ar[2] > (n/3))
        {
            ar[0] += ar[2] - (n/3);
            ans += ar[2] - (n/3);
            ar[2] = n/3;
        }

        cout << ans << "\n";
    }
}
