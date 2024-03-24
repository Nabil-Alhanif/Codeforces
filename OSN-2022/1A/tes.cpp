#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q, x;
    cin >> n >> q;

    ll half = (n + 1) / 2;
    // Kalau dia dibawah half, artinay index nya ganjil
    // kalau nggak ya genap

    ll maks = (n * (n + 1)) / 2;

    /*
    for (auto i:arr)
        cout << i << " ";
    cout << "\n";
    */

    while (q--) {
        cin >> x;

        if (x > maks) {
            cout << "0\n";
            continue;
        }

        ll ans = 0;

        ll total = 1 + n;
        ll need = x % total;
        ll butuh_dobel = x / total;
        ll tersedia_dobel = n / 2;

        if (need == 0)
            ans += tersedia_dobel + 1 - butuh_dobel;
        else if (need <= half) {
            ll sisa_dobel_kiri = need - 1;
            if (sisa_dobel_kiri >= butuh_dobel)
                ans++;
        }
        else {
            ll segmen_sekarang = total - need;
            ll sisa_dobel_kanan = tersedia_dobel - segmen_sekarang;
            if (sisa_dobel_kanan >= butuh_dobel)
                ans++;
        }

        //cout << x << " " << ans << " abis kiri\n";

        // Sekarang coba itung kalau dia nempel kanan kiri
        tersedia_dobel = (n - 1) / 2;
        total = n + 2;

        if (x % total == 0) {
            butuh_dobel = x / total;
            ans += tersedia_dobel + 1 - butuh_dobel;
        }

        cout << ans << "\n";
    }
}
