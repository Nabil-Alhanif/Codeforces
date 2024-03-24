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

        vector<int> input(n);
        vector<bool> exist(1025);

        for (auto &i:input)
        {
            cin >> i;
            exist[i] = 1;
        }

        bool flag = 1;
        for (int i = 1; i < 1024; i++)
        {
            flag = 1;
            for (auto j:input)
                flag &= exist[j ^ i];

            if (flag)
            {
                cout << i << "\n";
                break;
            }
        }

        if (!flag)
            cout << "-1\n";
    }
}
