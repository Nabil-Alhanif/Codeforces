#include <iostream>
using namespace std;

const int MAXS = 9;
int A[MAXS + 1];

void klik(int& i) {
    i--;
}

int klek(int x) {
	x--;
    if (x == MAXS)
        return A[x] * A[0];
    else
        return A[x] * A[x + 1];
}

int klok(int& i) {
    if (i == 0)
        return i;
    else {
        int tmp = i;
        klik(i);
        return klok(i) + klek(tmp);
    }
}

int main() {
    A[0] = 1; A[1] = 2; A[2] = 3; A[3] = 4; A[4] = 5;
    A[5] = 6; A[9] = 11; A[8] = 9; A[6] = 8; A[7] = 7;
    
    int n, i;
    cin >> n;
    i = n;

    cout << klok(i) << endl;

    return 0;
}

