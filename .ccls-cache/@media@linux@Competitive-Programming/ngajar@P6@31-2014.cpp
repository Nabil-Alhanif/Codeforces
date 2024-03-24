#include <iostream>
using namespace std;

int wow(int x) {
    if (x < 2)
        return x;
    else
        return wow(x - 2) + 3 * wow(x - 1);
}

int main() {
    cout << wow(5) << endl; // Example call to wow function
    return 0;
}

