#include <iostream>
using namespace std;

int main() {
    int merpati = 2018;

    if (merpati % 100 > 20)
        merpati += 1;
    else
        merpati += 2;

    cout << (merpati + merpati) << endl;

    return 0;
}

