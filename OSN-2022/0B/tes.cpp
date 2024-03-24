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

    ll q;
    cin >> q;

    ll cur = 0, in;
    for (int i = 0; i < q; i++) {
        cur++;
        cin >> in;

        if (in == cur)
            cout << "BENAR\n" << flush;
        else {
            cout << "SALAH\n" << flush;
            cur = 0;
        }
    }
}
