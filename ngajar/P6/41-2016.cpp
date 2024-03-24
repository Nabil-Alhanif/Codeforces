#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 5, 7, 8, 6, 8, 5, 8, 4, 6, 6, 3, 4, 2, 8, 0, 9, 2, 3, 4, 7, 8, 5, 4, 5, 3, 9, 8, 0, 3};
    int c = 0;
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_length; i++) {
        c += arr[i];
    }

    cout << fixed;
    cout.precision(2);
    cout << static_cast<double>(c) / arr_length << endl;

    return 0;
}

