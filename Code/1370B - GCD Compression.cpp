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
        int n, a;
        cin >> n;
        
        vector<int> ganjil, genap;
        for (int i = 0; i < n*2; i++)
        {
            cin >> a;
            if (a%2)
                ganjil.push_back(i+1);
            else genap.push_back(i+1);
            //cout << i << " ";
        }
        //cout << "\n";

        int cnt = 0;
        int jumlah_ganjil = ganjil.size();
        jumlah_ganjil -= (jumlah_ganjil%2);
        //cout << jumlah_ganjil << " jg\n";
        for (cnt; cnt < n-1 && cnt < jumlah_ganjil / 2; cnt++)
        {
            //cout << cnt << " cnt\n";
            cout << ganjil[cnt*2] << " " << ganjil[cnt*2+1] << "\n";
        }
        for (int i = 0; i < n-1-cnt; i++)
        {
            //cout << i << " i\n";
            cout << genap[i*2] << " " << genap[i*2+1] << "\n";
        }
    }
}
