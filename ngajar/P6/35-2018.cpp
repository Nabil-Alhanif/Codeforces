#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int i, j, s;

    // Initialize arr with values from 2 to 11
    for (i = 0; i < 10; i++)
        arr[i] = i + 2;

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (arr[i] == -1)
                break;

            s = arr[j] / arr[i];
            if (s * arr[i] == arr[j]) {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] -= arr[j];
                arr[i] = -1;
            }
        }
    }

    return 0;
}
