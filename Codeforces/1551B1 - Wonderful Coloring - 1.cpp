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
        string s;
        cin >> s;
        
        map<char, int> m;
        for (auto i:s)
            m[i]++;

        int ans = 0;
        for (auto i:m)
            ans += min(2, i.second);

        cout << ans / 2 << "\n";
    }
}
