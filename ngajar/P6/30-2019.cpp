#include <iostream>
#include <vector>
using namespace std;

int centaur = 4;

int kwekkwok(vector<int>& slark, int left, int right) { // Vector: Array
    int i = left, j = right, pivot = slark[(left + right) / 2];
    while (i <= j) {
        while (slark[i] < pivot)
            i++;
        while (slark[j] > pivot)
            j--;
        if (i <= j) {
            int tmp = slark[i];
            slark[i] = slark[j];
            slark[j] = tmp;
            i++;
            j--;
        }
    }
    if (slark[centaur] == pivot) {
        return pivot;
    } else if ((left < j) && (centaur >= left) && (centaur <= j)) {
        return kwekkwok(slark, left, j);
    } else if ((i < right) && (centaur >= i) && (centaur <= right)) {
        return kwekkwok(slark, i, right);
    }
    return -1;
}

int main() {
    vector<int> slark = {26, 12, 10, 17, 20, 14, 44, 35, 5, 24, 33};
    cout << kwekkwok(slark, 0, slark.size() - 1) << endl;
    return 0;
}
