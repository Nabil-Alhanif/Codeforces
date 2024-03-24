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

    ll n, p, q, x, ans = 0;
    cin >> n >> p >> q;

    vector<ll> bebek(n), asli(n);
    for (int i = 0; i < n; i++) {
        cin >> bebek[i];
        asli[i] = bebek[i];
    }
    sort(bebek.begin(), bebek.end());

    /*
    cout << "Bebek: ";
    for (auto i:bebek)
        cout << i << " ";
    cout << "\n";
    */

    vector<ll> segment(n);
    for (int i = 0; i < n; i++) {
        ll pos = i;
        for (ll l = i, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (bebek[i] + p >= bebek[mid]) {
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        segment[i] = pos;
    }

    /*
    for (int i = 0; i < n; i++)
        cout << i << " " << segment[i] << "\n";
    */

    while (q--) {
        cin >> x;
        x--;
        ans = 0;

        /*
        ll pos = 0;
        for (ll l = 0, r = n - 1, mid = (l + r) / 2; l <= r; mid = (l + r) / 2) {
            if (bebek[mid] < asli[x])
                l = mid + 1;
            else if (bebek[mid] == asli[x]) {
                pos = mid;
                r = mid - 1;
            }
            else r = mid - 1;
        }
        */

        for (int i = 0; i < n; i++) {
            if ((bebek[i] <= asli[x]) && (bebek[segment[i]] >= asli[x]))
                ans = max(ans, segment[i] - i + 1);
        }

        cout << ans << "\n";
    }
}
