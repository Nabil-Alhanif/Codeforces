#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q;
    cin >> q;

    int x, cnt = 0;
    while (q--) {
        cnt++;
        cin >> x;

        if (x == cnt)
            cout << "BENAR\n" << flush;
        else {
            cout << "SALAH\n" << flush;
            cnt = 0;
        }
    }
}
