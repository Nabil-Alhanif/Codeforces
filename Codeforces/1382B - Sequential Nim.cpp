#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        ll n, pile, one_count = 0;
        bool end = 0;
        string ans = "";

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> pile;
            if (pile == 1 && !end)
                one_count++;
            else
                end = 1;
        }

        if (one_count != n)
        {
            if (one_count % 2)
                ans = "Second\n";
            else ans = "First\n";
        }
        else
        {
            if (one_count % 2)
                ans = "First\n";
            else ans = "Second\n";
        }

        cout << ans;
    }
}
