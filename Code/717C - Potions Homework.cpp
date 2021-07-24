#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 10007, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, total = 0;
    cin >> n;

    vector<ll> task(n);
    for (auto &i:task)
        cin >> i;
    sort(task.begin(), task.end());

    for (int i = 0; i < n; i++)
    {
        total += (task[i] * task[n-1-i]);
        total %= MOD;
    }

    cout << total << "\n";
}
