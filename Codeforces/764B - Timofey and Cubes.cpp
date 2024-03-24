#include <bits/stdc++.h>
typedef int_fast64_t ll;
using namespace std;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ll> cube(n);
    for (auto &i:cube)
        cin >> i;

    for (int i = 0; i < n/2; i++)
    {
        if (!(i%2))
            swap(cube[i], cube[n-i-1]);
    }
    
    for (auto i:cube)
        cout << i << " ";
    cout << "\n";
}
