#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> v(n);
        while (n--)
        {
            int tmp;
            cin >> tmp;
            v[tmp-1]++;
            ans = max(ans, v[tmp-1]);
        }
        cout << ans << "\n";
    }
}