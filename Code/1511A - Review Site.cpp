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
        int n, ans = 0;
        cin >> n;
        
        vector<int> rev(n);
        for (auto &i:rev)
        {
            cin >> i;
            if (i % 2)
                ans++;
        }
        
        cout << ans << "\n";
    }
}
