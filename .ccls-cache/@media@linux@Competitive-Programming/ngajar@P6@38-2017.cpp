#include <iostream>
using namespace std;

void mystery(int a, int b) {
    if (a != b) {
        cout << "OSK2017" << endl;
        int m = (a + b) / 2;
        mystery(a, m);
        mystery(m, b);
    }
}

int main() {
    int a, b;
    cout << "Enter two integers a and b: ";
    cin >> a >> b;
    mystery(a, b);
    return 0;
}

