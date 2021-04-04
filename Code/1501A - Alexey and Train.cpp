#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

struct stasiun {
    ll dep = 0; // Departure
    ll arr = 0; // Arrrival
    ll late = 0; // Delay
    ll came = 0; // Lama perjalanan
    ll stay = 0; // Lama di stasiun
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<stasiun> tram(n+1);
        for (int i=1; i<=n; i++)
        {
            cin >> tram[i].arr >> tram[i].dep;
            tram[i].came = tram[i].arr - tram[i-1].dep;
            tram[i].stay = tram[i].dep - tram[i].arr;
            tram[i].stay = (tram[i].stay+1)/2;
        }
        for (int i=1; i<=n; i++)
        {
            cin >> tram[i].late;
            tram[i].arr = tram[i-1].dep + tram[i].late + tram[i].came;
            tram[i].dep = max(tram[i].dep, tram[i].arr + tram[i].stay);
        }
        cout << tram[n].arr << "\n";
    }
}