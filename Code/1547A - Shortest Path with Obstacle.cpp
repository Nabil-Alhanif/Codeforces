#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;

        /* Kalau mereka dalam satu garis, dan f ada di tengah tengah,
         * artinya jarak terdekatnya adalah garis lurus dari a ke b ditambah 2.
         * Ditambah 2 karena dia harus muterin tempat f nya
         */

        // Selain itu, jarak terdekatnya adalah abs(xa-xb) + abs(ya-yb)
        
        if (((xa == xb) && (xa == xf)) && (((yf > ya) && (yf < yb)) || ((yf < ya) && (yf > yb))))
            cout << abs(yb - ya) + 2 << "\n";
        else if (((ya == yb) && (ya == yf)) && (((xf > xa) && (xf < xb)) || ((xf < xa) && (xf > xb))))
            cout << abs(xb - xa) + 2 << "\n";
        else cout << abs(xb - xa) + abs(yb - ya) << "\n";
    }
}
