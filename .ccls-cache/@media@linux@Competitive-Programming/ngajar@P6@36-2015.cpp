#include <iostream>
using namespace std;

int main() {
    int x = 105;
    int y = 79;
    int xy;

    for (int i = 0; i <= 1234; i++) {
		// Menukar x dan y
        xy = x;
        x = y;
        y = xy;
    }

    cout << x << " " << y << endl;

    return 0;
}

