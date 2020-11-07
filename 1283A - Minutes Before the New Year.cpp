#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int minute=1440;
		int h, m;
		scanf("%d %d", &h, &m);
		h*=60;
		minute-=(m+h);
		printf("%d\n", minute);
	}
}
