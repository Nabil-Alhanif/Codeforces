#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string binary;
        cin >> binary;

        vector<int> bin(n);
        bin[0] = 1;
        binary[0]++;

        for (int i = 1; i < n; i++)
        {
            if (binary[i] + 1 != binary[i-1])
            {
                binary[i]++;
                bin[i]++;
            }
        }

        for (auto i:bin)
            cout << i;
        cout << "\n";
    }
}
