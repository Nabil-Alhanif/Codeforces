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

    int t, n, min_pos, max_pos;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> ar(n);
        for (int i = 0; i < n ; i++) {
            cin >> ar[i];

            if (ar[i] == 1)
                min_pos = i;

            if (ar[i] == n)
                max_pos = i;
        }

        /*
        int mins = ar[0], maks = ar[n - 1];

        if (min_pos > max_pos)
            swap(min_pos, max_pos);

        for (int i = 0; i < min_pos; i++)
            mins = min(mins, ar[i]);

        for (int i = max_pos; i < n; i++)
            maks = max(maks, ar[i]);

        if (mins < maks)
            cout << "YES\n";
        else cout << "NO\n";
        */
        if (ar[0] < ar[n-1])
            cout << "YES\n";
        else cout << "NO\n";
   }
}
