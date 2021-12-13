#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q, k, n;

    cin >> q >> k;
    while (q--) {
        cin >> n;
        if ((n | k) != n)
            cout << "-1\n";
        else cout << n << "\n";
    }
}
