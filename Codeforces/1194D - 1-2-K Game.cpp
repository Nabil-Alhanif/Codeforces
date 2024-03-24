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
        ll n, k;
        cin >> n >> k;

        bool alice = 1;
        if (k % 3)
        {
            alice = (bool)(n % 3);
        }
        else
        {
            ll rem = n % (k + 1);
            if ((rem % 3) == 0 && (rem != k))
                alice = 0;
        }

        if (alice)
            cout << "Alice\n";
        else cout << "Bob\n";
    }
}
