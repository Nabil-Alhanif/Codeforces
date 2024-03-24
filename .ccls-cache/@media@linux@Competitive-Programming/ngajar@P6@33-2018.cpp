#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int x = 80;

    for (int i = 1; i <= x; i++) {
        if (i % 3 == 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
