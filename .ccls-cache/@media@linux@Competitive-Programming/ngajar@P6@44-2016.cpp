#include <iostream>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    int c = 0;

    for (int i = 1; i <= n; i++) {
        int d = 1;
        for (int j = 1; j <= i; j++) {
            d *= r;
        }
        c += d;
    }

    cout << c << endl;

    return 0;
}

