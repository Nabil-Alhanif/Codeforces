#include <iostream>
using namespace std;

int arr[] = {8, 1, 6, 3, 4, 15};
int aduk[7];

void kalikali() {
    aduk[0] = 1;
    for (int i = 1; i <= 6; i++) {
        aduk[i] = aduk[i - 1] * arr[i - 1];
    }
}

int hasil(int kiri, int kanan) {
    return aduk[kanan] / aduk[kiri - 1];
}

int main() {
    kalikali();
    cout << aduk[3] << endl;
    cout << hasil(2, 3) << endl;
    cout << hasil(4, 6) << endl;
    return 0;
}
