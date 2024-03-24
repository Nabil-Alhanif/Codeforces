#include <iostream>
using namespace std;

int cnt = 0;

int naon(int x, int y) {
	cnt++;
	cout << "Pemanggilan ke: " << cnt << " dengan y = " << y << "\n";
    if (y == 0)
        return 1;
    else if (y == 1)
        return x;
    else
        return naon(x, y / 2) * naon(x, y / 2) * naon(x, y % 2);
}

int main() {
	naon(4, 13);
	cout << cnt << "\n";
    return 0;
}

