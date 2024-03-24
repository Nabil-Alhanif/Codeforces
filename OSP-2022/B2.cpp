#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;

struct kandang
{
    ll kapasitas;
    ll biaya;
};

bool comp(kandang &a, kandang &b)
{
    return (a.biaya < b.biaya);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll k;
    cin >> k;

    vector<kandang> kand(k);
    for (auto &i:kand)
        cin >> i.kapasitas;
    for (auto &i:kand)
        cin >> i.biaya;
    sort(kand.begin(), kand.end(), comp);

    /*
    cout << "Kandang:\n";
    for (auto i:kand)
        cout << i.kapasitas << " " << i.biaya << "\n";
    */

    ll n;
    cin >> n;

    vector<ll> bebek(n);
    for (auto &i:bebek)
        cin >> i;
    sort(bebek.begin(), bebek.end(), greater<ll>());

    /*
    cout << "Bebek:\n";
    for (auto i:bebek)
        cout << i << " ";
    cout << "\n";
    */

    ll ans = 0;
    for (ll i = 0, j = 0; i < n; i++) {
        ans += bebek[i] * kand[j].biaya;
        kand[j].kapasitas--;

        if (kand[j].kapasitas <= 0)
            j++;
    }

    cout << ans << "\n";
}
