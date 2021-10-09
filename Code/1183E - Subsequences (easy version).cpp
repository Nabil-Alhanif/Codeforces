#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;
const double PI = acos(-1);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;

    queue<string> q;
    set<string> st;

    q.push(s);
    st.insert(s);
    while (!q.empty() && st.size() < k)
    {
        string cur = q.front();
        int cur_size = cur.size();
        q.pop();

        for (int i = 0; i < cur_size; i++)
        {
            string tmp = cur;
            tmp.erase(i, 1); // Bikin string baru dengan ngapus satu char

            if (!st.count(tmp) && st.size() < k) // Cek string nya udah ada apa belum, kalau belum tambahin
            {
                q.push(tmp);
                st.insert(tmp);
                ans +=  (n - tmp.size());
            }
        }
    }

    if (st.size() < k)
        cout << "-1\n";
    else cout << ans << "\n";
}
