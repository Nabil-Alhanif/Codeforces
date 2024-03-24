#include <iostream>
using namespace std;

int main() {
    long long n, temp;
    cin >> n;

    while (n >= 10) {
        temp = 1;
        while (n > 0) {
            temp *= (n % 10);
            n /= 10;
        }
        n = temp;
    }

    cout << n << endl;

    return 0;
}

