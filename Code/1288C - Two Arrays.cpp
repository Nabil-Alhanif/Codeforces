#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
{
    for (auto i:vect) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m, ans = 0;
    cin >> n >> m;

    vector<vector<ll>> ar_a(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp_a(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> ar_b(n + 2, vector<ll>(m + 1));
    vector<vector<ll>> dp_b(n + 2, vector<ll>(m + 1));

    // Construct ar_a and dp_a
    for (int i = 1; i <= n; i++) {
        dp_a[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            ar_a[i][j] = dp_a[i][j - 1];
            dp_a[i][j] = (ar_a[i][j] + dp_a[i - 1][j]) % MOD;
        }
    }

    /*
    printVect2D(ar_a);
    printVect2D(dp_a);
    */

    // Construct ar_b and dp_b
    for (int i = n; i > 0; i--) {
        dp_b[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            ar_b[i][j] = dp_b[i][j - 1];
            dp_b[i][j] = (ar_b[i][j] + dp_b[i + 1][j]) % MOD;
        }
    }

    /*
    printVect2D(ar_b);
    printVect2D(dp_b);
    */

    for (int i = 1; i <= n; i++)
    {
        ans += (ar_a[i][m] * dp_b[i][m]);
        ans %= MOD;
    }
    cout << ans << "\n";
}
