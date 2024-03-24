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
        int n, a, b, cnt = 1, nol = 0;
        string s;
        cin >> n >> a >> b >> s;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i+1])
            {
                cnt++;
                if (s[i] == '0')
                    nol++;
            }
        }

        if (s[n-1] == '0')
            nol++;

        //cout << nol << " " << cnt << "\n";

        if (b >= 0)
            cout << (n * a) + (n * b) << "\n";
        else cout << (n * a) + (min(nol, cnt - nol) * b) + b << "\n";
    }
}
