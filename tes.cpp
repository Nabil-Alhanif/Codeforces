#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, inf = 1e13;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int>fib(500);
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i<500; i++)
        fib[i] = fib[i-1] + fib[i-2];
    int n;
    cin >> n;
    string name = string(n, 'o');
    for (auto i:fib)
    {
        if (i>n)
            break;
        name[i-1] = 'O';
    }
    cout << name << "\n";
}