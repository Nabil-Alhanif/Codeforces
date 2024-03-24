#include <iostream>
using namespace std;

long long tis(int a) {
    if (a < 10)
        return a;
    else
        return tis(a / 10) * 3 + tis(a / 50);
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Result: " << tis(num) << endl;
    return 0;
}

