#include <iostream>
using namespace std;

int ben(int x) {
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += i;
    }
    return ans;
}

int ten(int x) {
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += ben(i);
    }
    return ans;
}

int main() {
    cout << ten(4) << endl; // Example call to ten function
    return 0;
}

