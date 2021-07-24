#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, rem;
        cin >> a >> b;
        
        if (a == b)
        {
            cout << "0 0\n";
            continue;
        }

        rem = min(a % abs(a - b), abs(a - b) - (a % abs(a - b)));

        cout << abs(a-b) << " " << rem << "\n";
    }
}
