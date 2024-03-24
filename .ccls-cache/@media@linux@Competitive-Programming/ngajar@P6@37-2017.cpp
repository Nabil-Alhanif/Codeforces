#include <iostream>
using namespace std;

int f(int x) {
    if (x == 0)
        return 0;
    else
        return 1 - f(x - 1);
}

int main() {
    int x;
    cout << "Enter a value for x: ";
    cin >> x;
    cout << "f(" << x << ") = " << f(x) << endl;
    return 0;
}

