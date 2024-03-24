#include <iostream>
using namespace std;

int datas[] = {8, 12, 16, 20, 12, 14, 16, 20, 20, 22};

int itik(int a, int b) {
    if (b == 0)
        return a;
    else
        return itik(b, a % b);
}

int bebek(int x) {
    if (x > 10)
        return 0;
    else
        return itik(datas[x - 1], bebek(x * 2));
}

int main() {
    cout << bebek(1) << endl;
    return 0;
}
