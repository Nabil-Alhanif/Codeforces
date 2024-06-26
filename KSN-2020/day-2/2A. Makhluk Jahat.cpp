#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);

template <class type>
inline void printVect2D(vector<vector<type>> &vect)
{
    for (auto i:vect) {
        for (auto j:i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

inline void sieve(vector<bool> &vect)
{
    vect[0] = 1;
    vect[1] = 1;

    ll lim = vect.size() - 1;
 
    for (ll i = 2; i * i <= lim; i++) {
        for (ll j = i * i; j <= lim; j += i)
            vect[j] = 1;
    }
}

// Question specific constants
// Yeah I don't really like doing this...
const int N = 2e5 + 1;
const int K = 21;

int matrix[K][K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++)
            cin >> matrix[i][j];
    }
}
