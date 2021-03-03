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
        string a, b;
        cin >> a >> b;
        int sizeA = a.size(), sizeB = b.size();
        int lcm = sizeA*sizeB/__gcd(sizeA, sizeB);
        string aa = "", bb = "";
        for (int i=lcm/sizeA; i>0; i--)
            aa += a;
        for (int i=lcm/sizeB; i>0; i--)
            bb += b;
        if (aa==bb)
            cout << aa << "\n";
        else cout << "-1\n";
    }
}