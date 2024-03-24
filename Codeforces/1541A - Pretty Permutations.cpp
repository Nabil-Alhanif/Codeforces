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
        int n;
        cin >> n;
        if (n%2)
        {
            for (int i = 1; i < n/2; i++)
                cout << (i*2) << " " << (i*2)-1 << " ";
            cout << n-1 << " " << n << " " << n-2 << "\n";
        }
        else
        {
            for (int i = 1; i <= n/2; i++)
                cout << (i*2) << " " << (i*2)-1 << " ";
            cout << "\n";
        }
    }
}
