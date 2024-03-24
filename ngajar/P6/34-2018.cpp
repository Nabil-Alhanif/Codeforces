#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 5, 2, 1, 1, 7, 2};
    int cnt[11] = {0}; // Initialize cnt array with zeros
    int i, j;

    for (i = 0; i < 7; i++)
        cnt[arr[i]]++;

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= cnt[i]; j++)
            cout << i;
    }

    return 0;
}
