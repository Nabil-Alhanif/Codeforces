#include <bits/stdc++.h>
typedef int_fast32_t ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll ans = 0;
        while (b)
        {
            ans += (b-a);
            a /= 10;
            b /= 10;
        }

        cout << ans << "\n";
    }
}
