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
        string s;
        cin >> s;
        
        int n = s.size();
        int ans = (n-1) * 9;

        if (n == 1)
            ans += s[0] - '0';
        else
        {
            int mins = s[0]-'0';

            for (int i = 1; i < n; i++)
            {
                if (s[i] < s[i-1])
                {
                    mins = s[i-1] - '0' - 1;
                    break;
                }

                if (s[i] > s[i-1])
                    break;
            }

            ans += mins;
        }

        cout << ans << "\n";
    }
}
