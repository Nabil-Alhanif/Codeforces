#include <iostream>
using namespace std;

int main() {
    int kancil, panda, i, j;
    panda = 0;

    for (i = 2; i <= 100; i++) {
        j = 1;
        kancil = 0;
        while (j <= i) {
            if (i % j == 0)
                kancil++;
            j++;
        }
        if (kancil == 2)
            panda++;
    }

    cout << panda << endl;
    return 0;
}
