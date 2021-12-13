#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n, m, q, a, b, c, d, row, col;
    ll lr, lc, hr, hc;
    ll tmp;
    cin >> n >> m >> q;

    vector<vector<bool>> data(n, vector<bool>(m)), visit(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i][j] = !(i & j);
        }
    }

    cout << -1 << " ";
    for (int i = 0; i < m; i++)
        cout << i;
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        //cout << i << " ";
        for (int j = 0; j < m; j++) {
            if (data[i][j])
                cout << "#";
            else cout << "-";
        }
        cout << "\n";
    }

    ll ans, grup_kanan, grup_kiri, pkiri;
    while (q--) {
        cin >> a >> b >> c >> d;
        ans = 0;

        if ((a == 0) || (b == 0)) {
            cout << "1\n";
            continue;
        }

        for (ll i = 0; i < 32; i++) {
            tmp = (1ll << i);
            if (tmp < a)
                lr = i;
            if (tmp < b)
                lc = i;
            if (tmp <= c)
                hr = i;
            if (tmp <= d)
                hc = i;

            lr++;
            lc++;

            pkiri = (1ll << lr);

            // Itung jumlah grup ke kana
            grup_kanan = ((d + 1) / pkiri) - (b / pkiri);
        }
    }
}
