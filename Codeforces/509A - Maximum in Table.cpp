#include <bits/stdc++.h>
using namespace std;

int ar[10][10] ={{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
                {1, 3, 6, 10, 15, 21, 28, 36, 45, 55}, 
                {1, 4, 10, 20, 35, 56, 84, 120, 165, 220}, 
                {1, 5, 15, 35, 70, 126, 210, 330, 495, 715}, 
                {1, 6, 21, 56, 126, 252, 462, 792, 1287, 2002}, 
                {1, 7, 28, 84, 210, 462, 924, 1716, 3003, 5005}, 
                {1, 8, 36, 120, 330, 792, 1716, 3432, 6435, 11440}, 
                {1, 9, 45, 165, 495, 1287, 3003, 6435, 12870, 24310}, 
                {1, 10, 55, 220, 715, 2002, 5005, 11440, 24310, 48620}};
int main() {
	int a;
	cin >> a;
	cout << ar[a-1][a-1] << endl;
}