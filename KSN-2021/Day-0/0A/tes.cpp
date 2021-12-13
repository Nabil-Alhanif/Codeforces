#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, size;
    string s;
    bool flag;

    cin >> n >> s;
    sort(s.begin(), s.end());

    vector<string> ans;

    ans.push_back("");
    ans.back() += s[0];

    // Buat simpen ukuran dari vector ans
    size = 1;

    int l, r, mid, pos; // Jaga jaga kalau butuh binser
    for (int i = 1; i < n; i++) {
        if (ans.back().back() >= s[i]) { // Artinya ini harus bikin segmen baru
            ans.push_back("");
            ans.back() += s[i];
            size++;
            continue;
        }

        l = 0, r = size - 1, pos = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (ans[mid].back() < s[i]) {
                pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans[pos] += s[i];
    }

    sort(ans.begin(), ans.end());
    for (auto i:ans)
        cout << i << "\n";
}
