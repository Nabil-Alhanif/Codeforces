#include <iostream>
using namespace std;

int datas[] = {3, 9, 2, 6, 1, 4, 7, 8, 5, 10, 0};

void kambing2(int m) {
    if (m <= 5) {
        kambing2(m * 2);
        kambing2(m * 2 + 1);
        cout << datas[m] << " ";
    }
}

int main() {
    kambing2(1); // Start from index 1
    cout << endl;
    return 0;
}

