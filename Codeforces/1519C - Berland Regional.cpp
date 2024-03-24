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
        ll n, rem = 0;
        cin >> n;

        vector<pair<ll, vector<ll>>> univ(n);
        vector<ll> ans(n);

        ll u[n], s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> u[i];
            u[i]--;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            univ[u[i]].first++;
            univ[u[i]].second.push_back(s[i]);
        }

        for (auto &i:univ)
        {
            sort(i.second.begin(), i.second.end(), greater<ll>());
            for (int j = 1; j < i.first; j++)
                i.second[j] += i.second[j-1];

            for (int j = 1; j <= i.first; j++)
            {
                rem = i.first % j;
                //cout << "Rem " << rem << " " << i.second[i.first - 1 - rem] << "\n";
                ans[j - 1] += i.second[i.first - 1 - rem];
            }
        }

        for (auto i:ans)
            cout << i << " ";
        cout << "\n";

        /*
        for (auto i:univ)
        {
            for (auto j:i.second)
                cout << j << " ";
            cout << "\n";
        }
        */
    }
}
