#include <iostream>
using namespace std;

int main() {
    int a = 13;
    int b = 1;
    int n;
    
    cout << "Enter the value of n: ";
    cin >> n;

    while (a < n) {
        a = a + b;
        b = b + 1;
    }

    cout << a << " " << b << endl;

    return 0;
}

