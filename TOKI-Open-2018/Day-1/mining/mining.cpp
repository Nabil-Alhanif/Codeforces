#include "mining.h"
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void findGold() {

    /* Math oh math */

    /*
    int p;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (isIntegerDistance(i, j)) {
                p = i - 1;
                if (i == 1)
                    p = 2;
                if (!isIntegerDistance(p, j)) {
                    answer(p, j);
                    return;
                }
            }
        }
    }
    */

    unsigned int t = clock();
    rand_r(&t);
    t = clock();
    t %= random();
    rand_r(&t);
    // Nggak mungkin AC sih pake RNG, but who knows :D
    int x = random() % 1000 + 1;
    x %= random();
    int y = random() % 1000 + 1;
    y %= random();
    cout << x << " " << y << "\n";

    answer(x, y);
}
