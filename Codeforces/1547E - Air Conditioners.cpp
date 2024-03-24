#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> prefix(n+1), suffix(n+1);
        vector<pair<ll, ll>> air_con(k);

        for (auto &i:air_con)
            cin >> i.first;
        for (auto &i:air_con)
        {
            cin >> i.second;
            prefix[i.first] = i.second;
            suffix[i.first] = i.second;
        }
        sort(air_con.begin(), air_con.end());

        /* cur_air_con is the temperature
         * cur_air_con_pos is the position
         */
        ll cur_air_con = air_con[0].second, cur_air_con_pos = air_con[0].first, prob_new_temp;
        for (int i = air_con[0].first + 1; i <= n; i++)
        {
            if (prefix[i] == 0) // There is no air conditioner there
                prefix[i] = cur_air_con + abs(i - cur_air_con_pos);
            else
            {
                // Possible new temperature
                prob_new_temp = cur_air_con + abs(i - cur_air_con_pos);

                if (prefix[i] < prob_new_temp)
                {
                    cur_air_con = prefix[i];
                    cur_air_con_pos = i;
                }
                else prefix[i] = prob_new_temp;
            }
        }

        cur_air_con = air_con[k-1].second, cur_air_con_pos = air_con[k-1].first;
        for (int i = air_con[k-1].first - 1; i > 0; i--)
        {
            if (suffix[i] == 0)
                suffix[i] = cur_air_con + abs(i - cur_air_con_pos);
            else
            {
                // Possible new temperature
                prob_new_temp = cur_air_con + abs(i - cur_air_con_pos);

                if (suffix[i] < prob_new_temp)
                {
                    cur_air_con = suffix[i];
                    cur_air_con_pos = i;
                }
                else suffix[i] = prob_new_temp;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (prefix[i] == 0)
                cout << suffix[i];
            else if (suffix[i] == 0)
                cout << prefix[i];
            else cout << min(suffix[i], prefix[i]);
            cout << " ";
        }
        cout << "\n";
    }
}
