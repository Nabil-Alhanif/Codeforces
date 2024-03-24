#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, ans = 0;
    cin >> n >> k;

    vector<ll> atas_genap, atas_ganjil, kiri_genap, kiri_ganjil;

    // Koordinat nya dari 0 ya ges
    vector<pair<ll, ll>> bomb(k);
    for (int i = 0; i < k; i++) {
        cin >> bomb[i].fi >> bomb[i].se;
        bomb[i].fi--, bomb[i].se--;

        ll tmp = bomb[i].se - bomb[i].fi;
        if (tmp >= 0) {
            if (tmp % 2)
                atas_ganjil.push_back(tmp);
            else atas_genap.push_back(tmp);
        }
        else {
            tmp = -tmp;
            if (tmp % 2)
                kiri_ganjil.push_back(tmp);
            else kiri_genap.push_back(tmp);
        }
    }

    // Remove duplicate elements
    sort(atas_genap.begin(), atas_genap.end());
    atas_genap.resize(distance(atas_genap.begin(), unique(atas_genap.begin(), atas_genap.end())));

    ll atas_genap_size = atas_genap.size();
    for (int i = 0; i < atas_genap_size; i++)
        ans += min(n - atas_genap[i], n);

    sort(atas_ganjil.begin(), atas_ganjil.end());
    atas_ganjil.resize(distance(atas_ganjil.begin(), unique(atas_ganjil.begin(), atas_ganjil.end())));

    ll atas_ganjil_size = atas_ganjil.size();
    for (int i = 0; i < atas_ganjil_size; i++)
        ans += min(n - atas_ganjil[i], n);

    sort(kiri_genap.begin(), kiri_genap.end());
    kiri_genap.resize(distance(kiri_genap.begin(), unique(kiri_genap.begin(), kiri_genap.end())));

    ll kiri_genap_size = kiri_genap.size();
    for (int i = 0; i < kiri_genap_size; i++)
        ans += min(n - kiri_genap[i], n);

    sort(kiri_ganjil.begin(), kiri_ganjil.end());
    kiri_ganjil.resize(distance(kiri_ganjil.begin(), unique(kiri_ganjil.begin(), kiri_ganjil.end())));

    ll kiri_ganjil_size = kiri_ganjil.size();
    for (int i = 0; i < kiri_ganjil_size; i++)
        ans += min(n - kiri_ganjil[i], n);

    /*
    cout << "Ans: " << ans << "\n";

    cout << "Atas ganjil: ";
    for (auto i:atas_ganjil)
        cout << i << " ";
    cout << "\n";

    cout << "Atas genap: ";
    for (auto i:atas_genap)
        cout << i << " ";
    cout << "\n";

    cout << "Kiri ganjil: ";
    for (auto i:kiri_ganjil)
        cout << i << " ";
    cout << "\n";

    cout << "Kiri genap: ";
    for (auto i:kiri_genap)
        cout << i << " ";
    cout << "\n";
    */

    set<ll> sec_pos;

    for (int i = 0; i < k; i++) {
        ll p1 = max((ll)0, bomb[i].fi - (n - bomb[i].se - 1));
        ll p2 = min(n - 1, bomb[i].fi + bomb[i].se);
        //cout << p1 << " " << p2 << " p1p2\n";
        if (p1 == 0)
            sec_pos.insert(p2);
        else sec_pos.insert(p1 - p2);
    }

    /*
    cout << "sec: ";
    for (auto i:sec_pos)
        cout << i << " ";
    cout << "\n";
    */

    for (auto j:sec_pos) {
        ll i = abs(j);
        ans += (i + 1);
        if (i % 2) {
            ll p1 = 0;
            for (int l = 0, r = atas_ganjil_size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (atas_ganjil[mid] <= i) {
                    p1 = mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans -= p1;

            ll p2 = 0;
            for (int l = 0, r = kiri_ganjil_size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (kiri_ganjil[mid] <= i) {
                    p2 = mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans -= p2;

            //cout << (p1 + p2) << " cross\n";
        }
        else {
            ll p1 = 0;
            for (int l = 0, r = atas_genap_size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (atas_genap[mid] <= i) {
                    p1 = mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans -= p1;

            ll p2 = 0;
            for (int l = 0, r = kiri_genap_size - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
                if (kiri_genap[mid] <= i) {
                    p2 = mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans -= p2;

            //cout << (p1 + p2) << " cross\n";
        }
    }

    //cout << ans << "\n";
    ans = (n * n) - ans;
    cout << ans << "\n";
}
