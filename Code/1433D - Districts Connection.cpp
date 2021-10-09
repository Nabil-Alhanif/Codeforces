#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

inline void sieve(vector<bool> &vect, int lim = 1e6)
{
    vect[0] = 1;
    vect[1] = 1;

    for (int i = 2; i * i <= lim; i++)
    {
        for (int j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> district(n);
        map<int, int> cnt;

        for (auto &i:district)
        {
            cin >> i;
            cnt[i]++;
        }

        vector<pair<int, int>> size;
        for (auto &i:cnt)
            size.push_back({i.second, i.first});
        sort(size.begin(), size.end());

        vector<int> root, not_root;
        for (int i = 0; i < n; i++)
        {
            if (district[i] == size[0].second)
                root.push_back(i + 1);
            else not_root.push_back(i + 1);
        }

        int mins = size[0].first;
        if (mins - 1 > n - mins)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            for (auto i:not_root)
                cout << root[0] << " " << i << "\n";

            int size = root.size();
            for (int i = 1; i < size; i++)
            {
                cout << root[i] << " " << not_root[0] << "\n";
            }
        }
    }
}
