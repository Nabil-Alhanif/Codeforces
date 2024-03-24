#include <iostream>
using namespace std;

void func(int n)
{
    int count;
    count = 0;

    do {
        n = (n * n + 5) % 23;
        count++;
    } while (n != 0);

	for (int i = 0; i < 23; i++)
	cout << count << "\n";
}

int main() {
	for (int i = 0; i < 23; i++)
		func(i);

    return 0;
}

