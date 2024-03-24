#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q, k, c;
    cin >> q >> k;

    while (q--) {
        cin >> c;

        bool bisa = 1;
        for (int i = 0; i <= 30; i++) {
            if (k & (1 << i)) {
                //cout << (k & (1 << i)) << " " << (c & (1 << i)) << "\n";
                bisa &= ((c & (1 << i)) != 0);
            }
        }

        cout << (bisa ? c : -1) << "\n";
    }
}
