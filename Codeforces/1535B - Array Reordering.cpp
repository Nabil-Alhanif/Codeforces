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
        int n, ans = 0, odd = 0, even = 0, tmp;
        cin >> n;

        vector<int> odd_num;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (tmp%2)
            {
                odd++;
                odd_num.push_back(tmp);
            }
            else even++;
        }

        ans = (even * odd) + (even * (even-1) / 2);

        for (int i = 0; i < odd - 1; i++)
        {
            for (int j = i + 1; j < odd; j++)
            {
                if (__gcd(odd_num[i], odd_num[j]) > 1)
                    ans++;
            }
        }

        cout << ans << "\n";
    }
}
