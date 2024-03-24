#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll p, q, r;
    cin >> p >> q >> r;

    ll n, t;
    cin >> n;

    while (n--) {
        cin >> t;
        ll ans = 0;
        ans |= t % p;
        ans |= t % q;
        ans |= t % r;

        cout << (ans ? "TIDAK" : "YA") << "\n";
    }
}
