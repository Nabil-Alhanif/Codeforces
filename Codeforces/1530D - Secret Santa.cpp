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
        int n;
        cin >> n;

        vector<ll> wanted_list(n+1);
        vector<ll> ans(n+1);
        vector<bool> given(n+1);
        vector<vector<ll>> gift_list(n+1);

        for (int i = 1; i <= n; i++)
        {
            cin >> wanted_list[i];
            gift_list[wanted_list[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (gift_list[i].empty())
                continue;

            ll gifted = gift_list[i][0];
            for (auto gift_by:gift_list[i])
            {
                if (gift_list[gift_by].empty())
                {
                    gifted = gift_by;
                    break;
                }
            }

            ans[gifted] = i;
            given[i] = 1;
        }

        vector<ll> ungiven, hasnt_give, complement;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0 && !given[i])
                complement.push_back(i);
            else if (ans[i] == 0)
                hasnt_give.push_back(i);
            else if (!given[i])
                ungiven.push_back(i);
        }

        if (complement.size() == 1)
        {
            ans[hasnt_give[0]] = complement[0];
            ans[complement[0]] = ungiven[0];

            int size = ungiven.size();
            for (int i = 1; i < size; i++)
                ans[hasnt_give[i]] = ungiven[i];
        }
        else
        {
            if (!complement.empty())
                ans[complement[0]] = complement[complement.size()-1];
            for (int i = 1; i < complement.size(); i++)
                ans[complement[i]] = complement[i-1];

            int size = ungiven.size();
            for (int i = 0; i < size;  i++)
                ans[hasnt_give[i]] = ungiven[i];
        }

        cout << n - (complement.size() + ungiven.size()) << "\n";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
