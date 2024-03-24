#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        
        ans = n - 1; // Base case if n is prime

        for (int i = 2; i*i <= n; i++)
        {
            int rem = n % i; // Find the remainder;
            ans = min(ans, i + rem);
            
            /*
             * So the logic is like this
             * 
             * We have number a, b, and c
             * c is a * b and c <= n
             * There is 1 division operation, c / max(a, b) = min(a, b)
             * Then, there is min(a, b) substraction operation to get it to 1
             * There is also n - c subtraction operation to get it from n to c
             * So in total there is min(a, b) + (n - c) operation
             * 
             * Then we just have to check for all possible a and b to get the minimum operation
             */
        }

        cout << ans << "\n";
    }
}
