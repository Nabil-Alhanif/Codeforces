#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll bigpow(ll base, ll power)
{
    if (power == 0)
        return 1;
    if (power == 1)
        return base;

    ll half = bigpow(base, power / 2);
    half *= half;
    half %= MOD;

    if (power % 2)
        return ((half * base) % MOD);
    return (half % MOD);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n, a, ans = 0;
    bool flag = 0;

    cin >> n;
    vector<ll> kiri, kanan;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!flag)
            kiri.push_back(a);
        else kanan.push_back(a);

        if (a == 1) {
            flag = 1;
            kanan.push_back(a);
        }
    }

    /*
    for (auto i:kiri)
        cout << i << " ";
    cout << "\n";

    for (auto i:kanan)
        cout << i << " ";
    cout << "\n";
    */

    set<pair<ll, ll>> skiri, skanan;
    ll nkiri = kiri.size(), nkanan = kanan.size();

    vector<ll> dpkiri(nkiri), dpkanan(nkanan);
    vector<ll> poskiri(nkiri), poskanan(nkanan);

    dpkiri.back() = 1;
    dpkanan.front() = 1;
    poskiri.back() = nkiri - 1;
    poskanan.front() = 0;

    skiri.insert({1, nkiri - 1});
    skanan.insert({1, 0});

    set<pair<ll, ll>>::iterator itr;
    ll pos;
    for (int i = nkiri - 2; i >= 0; i--) {
        itr = (skiri.lower_bound({kiri[i], 1e9}));
        itr--;
        pos = (*itr).se;

        skiri.insert({kiri[i], i});

        poskiri[i] = pos;
        if (i != 0) {
            if ((kiri[i] > kiri[i - 1]) || (kiri[i] > kiri[i + 1]))
                dpkiri[i] = dpkiri[i + 1] * 2;
            else dpkiri[i] = dpkiri[i + 1] + dpkiri[pos];
        }
        else {
            if (kiri[i] > kiri[i + 1])
                dpkiri[i] = dpkiri[i + 1] * 2;
            else dpkiri[i] = dpkiri[i + 1] + dpkiri[pos];
        }
        dpkiri[i] %= MOD;
    }

    /*
    cout << "poskiri\n";
    for (auto i:poskiri)
        cout << i << " ";
    cout << "\n";

    cout << "dpkiri\n";
    for (auto i:dpkiri)
        cout << i << " ";
    cout << "\n";
    */

    for (int i = 1; i < nkanan; i++) {
        itr = skanan.lower_bound({kanan[i], 1e9});
        itr--;
        pos = (*itr).se;

        skanan.insert({kanan[i], i});

        poskanan[i] = pos;
        if (i != nkanan - 1) {
            if ((kanan[i] > kanan[i - 1]) || (kanan[i] > kanan[i + 1]))
                dpkanan[i] = dpkanan[i - 1] * 2;
            else dpkanan[i] = dpkanan[i - 1] + dpkanan[pos];
        }
        else {
            if (kanan[i] > kanan[i - 1])
                dpkanan[i] = dpkanan[i - 1] * 2;
            else dpkanan[i] = dpkanan[i - 1] + dpkanan[pos];
        }
        dpkanan[i] %= MOD;
    }

    /*
    cout << "poskanan\n";
    for (auto i:poskanan)
        cout << i << " ";
    cout << "\n";

    cout << "dpkanan\n";
    for (auto i:dpkanan)
        cout << i << " ";
    cout << "\n";
    */

    __int128_t tmp = dpkiri.front() * dpkanan.back();
    tmp %= MOD;
    ans = tmp % MOD;
    cout << ans << "\n";
}
