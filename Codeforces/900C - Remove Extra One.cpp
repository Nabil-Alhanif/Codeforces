#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, p, largest = -1, second_largest = -1;
    cin >> n;

    vector<int> prob(n + 1); // Prob itu probabilty dia yang dibuang
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p > largest)
        {
            /**
             * Kalau dia yang terbesar sampai dengan saat ini,
             * maka kemungkinan dia dibuang lebih kecil,
             * karena dia adalah yang paling belakang dalam
             * sebuah deret bialngan records.
             */
            second_largest = largest;
            largest = p;
            prob[p]--;
        }
        else if (p > second_largest)
        {
            /**
             * Namun, apabila dia lebih kecil daripada 
             * yang terbesar dan lebih besar daripada 
             * kedua terbesar, maka kemungkinan untuk
             * si terbesar dibuang bertambah, 
             * karena itu artinya ada angka yang lebih
             * kecil di belakang si terbesar sampai 
             * sekarang (buktinya p), dan apabila
             * si terbesar nggak dibuang, deret records
             * nya kemunginan selesai disini.
             * Oleh karena itu, kemungkinan dibuangnya
             * bertambah.
             * Dan saya penasaran kenapa soal ini tag nya bukan DP.
             */
            second_largest = p;
            prob[largest]++;
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (prob[i] > prob[ans])
            ans = i;
    }
    cout << ans << "\n";
}
