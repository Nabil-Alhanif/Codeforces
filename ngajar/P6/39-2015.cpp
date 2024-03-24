#include <iostream>
using namespace std;

int swag(int x) {
    if (x < 7)
        return x;
    else
        return swag(x % 7) * swag(x / 7) * 7;
}

int main() {
    cout << swag(71) << endl;
	cout << swag(10) << endl;
	cout << swag(22) << endl;
    return 0;
}

