#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, col_ans = INT_MAX, row_ans = INT_MAX, col_need = -1, row_need = -1;
        cin >> n >> m;

        vector<vector<char>> painting(n, vector<char>(m));
        for (auto &row:painting)
        {
            for (auto &col:row)
                cin >> col;
        }

        vector<int> cnt_row(n), cnt_col(m);
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                cnt_row[row] += (painting[row][col] == '.');
                cnt_col[col] += (painting[row][col] == '.');
            }
        }

        int ans = n + m;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
                ans = min(ans, cnt_row[row] + cnt_col[col] - (painting[row][col] == '.'));
        }

        cout << ans << "\n";
    }
}
