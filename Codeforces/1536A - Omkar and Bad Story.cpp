#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n, mins = INT_MAX, maks = INT_MIN, b;
        cin >> n;

        while (n--)
        {
            cin >> b;
            mins = min(mins, b);
            maks = max(maks, b);
        }

        if (mins < 0)
            cout << "No\n";
        else
        {
            cout << "Yes\n" << maks+1 << "\n";
            for (int i = 0; i <= maks; i++)
                cout << i << " ";
            cout << "\n";
        }
    }
}
