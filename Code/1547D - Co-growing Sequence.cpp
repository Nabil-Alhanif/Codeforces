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
        int n, tmp;
        cin >> n;

        vector<int> seq(n);
        for (auto &i:seq)
            cin >> i;

        // As it has to be lexicographically smaller, first member of b must be 0
        cout << "0";

        for (int i = 1; i < n; i++)
        {
            tmp = (seq[i] | seq[i-1]);

            cout << " " << (int)((int)tmp ^ (int)seq[i]);
            seq[i] = tmp;
        }

        cout << "\n";
    }
}
