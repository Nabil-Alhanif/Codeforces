#include <iostream>
using namespace std;

int asik(int a, int b, int x) {
    for (int i = 1; i <= x; i++) {
        a = a + b;
    }
    return a;
}

int seru(int a, int b, int x) {
    for (int i = 1; i <= x; i++) {
        a = a - b;
        break;
    }
    return a;
}

int main() {
	cout << asik(1, 9, 5) << "\n";
	cout << asik(15, 9, 2000) << "\n";
	cout << seru(asik(15, 9, 2000), 9, 2000) << "\n";
    return 0;
}
