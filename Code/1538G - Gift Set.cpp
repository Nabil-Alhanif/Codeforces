#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll x, y, a, b, ans = 0;
        cin >> x >> y >> a >> b;

        if (a < b)
            swap(a, b);

        // Pertama, bikin binser buat dapet jumlah paket
        ll l = 0, r = 1e9, paket_total, paket_satu, permen_merah, permen_biru, right_bound, left_bound;
        while (l <= r)
        {
            paket_total = (l + r) / 2;

            bool memungkinkan = 0;
            right_bound = paket_total;
            left_bound = 0;
            while (left_bound <= right_bound)
            {
                paket_satu = (left_bound + right_bound) / 2;

                // Hitung jumlah permen merah dan biru
                permen_merah = (a * paket_satu) + (b * (paket_total - paket_satu));
                permen_biru = (a * (paket_total - paket_satu)) + (b * paket_satu);

                // Kalau dua duanya kebanyakan, langsung break aja
                if (permen_merah > x && permen_biru > y)
                {
                    memungkinkan = 0;
                    break;
                }

                // Cek apakah dua duanya memungkinkan
                if (permen_merah <= x && permen_biru <= y)
                {
                    memungkinkan = 1;
                    break;
                }

                /** Apabila permen merah kebanyakan, 
                 * maka paket satu dikurangi, 
                 * karena a pasti lebih besar dari b 
                 * (liat if dan swap di baris 19), 
                 * dan paket satu dikaliin sama a, jadi harus dikurangi.
                 *
                 * Di sisi lain...
                 * Apabila permen biru kebanyakan, 
                 * Paket satu dibanyakin,
                 * karena a dikali sama paket dua
                 * jadi makin banyak paket satu, makin sedikit paket dua
                 */
                if (permen_merah > x && permen_biru <= y)
                {
                    right_bound = paket_satu - 1;
                }
                else
                {
                    left_bound = paket_satu + 1;
                }
            }

            if (permen_merah <= x && permen_biru <= y)
                memungkinkan = 1;

            if (memungkinkan)
            {
                ans = paket_total;
                l = paket_total + 1;
            }
            else
            {
                r = paket_total - 1;
            }
        }

        cout << ans << "\n";
    }
}
