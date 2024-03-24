#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef int_fast64_t ll;
typedef uint_fast64_t ull;
typedef __uint128_t u128_t;
typedef __int128_t i128_t;


inline ll ask(ll l, ll r)
{
    ll ret;
    cout << "? " << l << " " << r << "\n";
    cout << flush;
    cin >> ret;
    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    if (n == 1)
        return cout << "! 1\n" << flush, 0;

    if (n == 2)
        return cout << "! 1 2\n" << flush, 0;

    vector<ll> ans(n + 1);
    vector<bool> vis(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));

    ll largest = 2;
    for (int i = n - 1; i > 1; i--) {
        dp[1][i] = ask(1, i);

        if (dp[1][i] != n - 1) {
            largest = i + 1;
            break;
        }
    }
    ans[largest] = n;
    vis[ans[largest]] = 1;

    /*
    cout << "Found largest number on: " << largest << "\n";
    cout << "Current ans: ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    */

    // Dapetin angka sebelah kanan nya
    if (largest != n) {
        dp[largest][largest + 1] = ask(largest, largest + 1);
        ans[largest + 1] = n - dp[largest][largest + 1];
        vis[ans[largest + 1]] = 1;
    }

    /*
    cout << "Current ans: ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    */

    // Ini nggak perlu pake cek karena 1 pasti sebelum n
    // Dapetin angka sebelah kiri nya
    dp[largest - 1][largest] = ask(largest - 1, largest); {
        ans[largest - 1] = n - dp[largest - 1][largest];
        vis[ans[largest - 1]] = 1;
    }

    /*
    cout << "Current ans: ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    */

    // Itung buat sebelah kanan
    for (int i = largest + 2; i <= n; i++) {
        dp[i - 1][i] = ask(i - 1, i);
        if (ans[i - 1] - dp[i - 1][i] < 1) {
            ans[i] = ans[i - 1] + dp[i - 1][i];
            //cout << "Can't reduce ans!\n";
        }
        else if (ans[i - 1] + dp[i - 1][i] > n) {
            ans[i] = ans[i - 1] - dp[i - 1][i];
            //cout << "Can't increase ans!\n";
        }
        else if (vis[ans[i - 1] - dp[i - 1][i]]) {
            ans[i] = ans[i - 1] + dp[i - 1][i];
            //cout << "Lower ans already exist!\n";
        }
        else if (vis[ans[i - 1] + dp[i - 1][i]]) {
            ans[i] = ans[i - 1] - dp[i - 1][i];
            //cout << "Higher ans already exist!\n";
        }
        else {
            dp[i - 2][i] = ask(i - 2, i);
            //cout << "Current trinity: " << "i - 2 : i -> " << dp[i - 2][i] << " i - 2 : i - 1 -> " << dp[i - 2][i - 1] << " i - 1 : i -> " << dp[i - 1][i] << "\n";
            if (dp[i - 2][i - 1] == dp[i - 2][i]) {
                if (ans[i - 2] > ans[i - 1])
                    ans[i] = ans[i - 1] + dp[i - 1][i];
                else ans[i] = ans[i - 1] - dp[i - 1][i];
            }
            else if (dp[i - 1][i] == dp[i - 2][i]) {
                if (ans[i - 2] > ans[i - 1])
                    ans[i] = ans[i - 1] + dp[i - 1][i];
                else ans[i] = ans[i - 1] - dp[i - 1][i];
            }
            else {
                if (ans[i - 2] > ans[i - 1])
                    ans[i] = ans[i - 1] - dp[i - 1][i];
                else ans[i] = ans[i - 1] + dp[i - 1][i];
            }
        }

        /*
        cout << "Current ans: ";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
        */

        vis[ans[i]] = 1;
    }

    for (int i = largest - 2; i >= 1; i--) {
        dp[i][i + 1] = ask(i, i + 1);
        if (ans[i + 1] - dp[i][i + 1] < 1) {
            ans[i] = ans[i + 1] + dp[i][i + 1];
            //cout << "Can't reduce ans!\n";
        }
        else if (ans[i + 1] + dp[i][i + 1] > n) {
            ans[i] = ans[i + 1] - dp[i][i + 1];
            //cout << "Can't increase ans!\n";
        }
        else if (vis[ans[i + 1] - dp[i][i + 1]]) {
            ans[i] = ans[i + 1] + dp[i][i + 1];
            //cout << "Lower ans already exist!\n";
        }
        else if (vis[ans[i + 1] + dp[i][i + 1]]) {
            ans[i] = ans[i + 1] - dp[i][i + 1];
            //cout << "Higher ans already exist!\n";
        }
        else {
            dp[i][i + 2] = ask(i, i + 2);
            //cout << "Current trinity: " << "i : i + 2 -> " << dp[i][i + 2] << " i : i + 1 -> " << dp[i][i + 1] << " i + 1 : i + 2 -> " << dp[i + 1][i + 2] << "\n";
            if (dp[i + 1][i + 2] == dp[i][i + 2]) {
                if (ans[i + 2] > ans[i + 1])
                    ans[i] = ans[i + 1] + dp[i][i + 1];
                else ans[i] = ans[i + 1] - dp[i][i + 1];
            }
            else if (dp[i][i + 1] == dp[i][i + 2]) {
                if (ans[i + 2] > ans[i + 1])
                    ans[i] = ans[i + 1] + dp[i][i + 1];
                else ans[i] = ans[i + 1] - dp[i][i + 1];
            }
            else {
                if (ans[i + 2] > ans[i + 1])
                    ans[i] = ans[i + 1] - dp[i][i + 1];
                else ans[i] = ans[i + 1] + dp[i][i + 1];
            }
        }

        /*
        cout << "Current ans: ";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
        */

        vis[ans[i]] = 1;
    }

    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << ans[i];
    cout << "\n";
    cout << flush;
}
