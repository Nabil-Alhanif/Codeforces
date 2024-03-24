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
        ll r, b, d;
        cin >> r >> b >> d;
        
        ll dif = abs(r-b);
        dif = (dif + min(r, b) - 1) / min(r, b);

        cout << (dif>d?"NO\n":"YES\n");
    }
}
