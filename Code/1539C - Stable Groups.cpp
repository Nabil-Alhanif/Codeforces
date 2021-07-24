#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> student(n);
    vector<ll> dif;

    for (auto &i:student)
        cin >> i;

    sort(student.begin(), student.end());
    for (int i = 0; i < n-1; i++)
    {
        if ((student[i+1] - student[i]) > x)
            dif.push_back(student[i+1] - student[i] - 1);
    }

    sort(dif.begin(), dif.end());

    ll ans = dif.size() + 1, tmp;
    for (auto i:dif)
    {
        tmp = i/x;
        if (tmp <= k)
        {
            k -= tmp;
            ans--;
        }
    }

    cout << ans << "\n";
}
