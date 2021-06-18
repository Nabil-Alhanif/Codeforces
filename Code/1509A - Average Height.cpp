#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> genap, ganjil;
        while (n--)
        {
            int height;
            cin >> height;
            
            if (height % 2)
                ganjil.push_back(height);
            else genap.push_back(height);
        }
        
        for (auto i:ganjil)
            cout << i << " ";
        for (auto i:genap)
            cout << i << " ";
        cout << "\n";
    }
}
