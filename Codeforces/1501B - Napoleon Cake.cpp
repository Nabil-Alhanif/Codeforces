#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> cake(n);
        for (int i=0; i<n; i++)
        {
            int dress;
            cin >> dress;
            if (!dress)
                continue;
            dress--;
            cake[max(0, i-dress)]++;
            if (i+1<n)
                cake[i+1]--;
        }
        for (int i=1; i<n; i++)
            cake[i] += cake[i-1];
        for (auto i:cake)
            if (i)
                cout << "1 ";
            else cout << "0 ";
        cout << "\n";
    }
}