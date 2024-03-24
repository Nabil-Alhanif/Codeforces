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
        int ar[4], s[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> s[i];
            ar[i] = s[i];
        }
        sort(ar, ar+4);

        if (((s[0] == ar[3]) && (s[1] == ar[2])) || ((s[1] == ar[3]) && (s[0] == ar[2])))
        {
            cout << "NO\n";
            continue;
        }
 
        if (((s[2] == ar[3]) && (s[3] == ar[2])) || ((s[3] == ar[3]) && (s[2] == ar[2])))
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
   }
}
