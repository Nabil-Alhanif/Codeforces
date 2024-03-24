#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double n, r;
    cin >> n >> r;
    // Sumpah Bil, lain kali jangan males bikin binser dan malah ngabisin sejam ngutak ngatik math -_-
    cout << fixed << setprecision(12) << (r * ((sin(PI/n) / (1 - sin(PI/n))))) << "\n";
}
