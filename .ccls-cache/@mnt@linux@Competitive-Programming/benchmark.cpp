#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    chrono::steady_clock::time_point begin, end;

    cout << "Normal iteration\n";
    begin = chrono::steady_clock::now();
    vector<int> ar1(1e7);
    for (int i = 0; i < 1e5 + 5; i++)
        ar1[i] = 1;
    end = chrono::steady_clock::now();
    cout << "Elapsed time (sec) = " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 10000000.0 << "\n";

    cout << "Auto iteration\n";
    begin = chrono::steady_clock::now();
    vector<int> ar2(1e7);
    for (auto &i:ar2)
        i = 1;
    end = chrono::steady_clock::now();
    cout << "Elapsed time (sec) = " << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 10000000.0 << "\n";
}
