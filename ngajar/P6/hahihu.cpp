#include <bits/stdc++.h>
using namespace std;

int ayam(int a, int b)
{
	int ret = 0;
	for (int i = a; i <= b; i++)
		ret *= i;
	return ret;
}

void bebek(int a, int b)
{
	int ret = 0;
	for (int i = ayam(a, b); i <= a * b; i++) {
		if (i % a == 0)
			ret += b;
	}
	cout << ret << "\n";
}

int kucing(int miaw, int maung)
{
	int huha = 0;
	for (int i = 0; miaw <= maung; maung /= 2, i++) {
		huha += pow(2, i);
	}
	return huha;
}

void empat()
{
	int arr[6] = {5, 2, 4, 1, 3, 6};
	for (int i = 0; i < 6; i++) {
		int cnt = 0;
		for (int j = i + 1; j < 6; j++) {
			if (arr[j] <= arr[i]) {
				swap(arr[i], arr[j]);
				break;
			}
		}
	}

	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void kambing(int a)
{
	int ret = 1;
	for (int i = 0; i < 8; i++) {
		if (a & (1 << i))
			ret *= (1 << i);
	}
	cout << ret << "\n";
}

void hitung(int a, int b)
{
	int cnt = 0;
	do {
		if (b % a == 0)
			cnt++;
		a--;
	} while(a > 0);
	cout << cnt << "\n";
}

void telor(int a, int b, int c)
{
	if (a > b) {
		if (b > c)
			cout << "Yes\n";
		else if (a > c)
			cout << "No\n";
	}
	if (a > c)
		cout << "Yes\n";
	else if (b > c)
		cout << "Yes\n";
	else cout << "No\n";
}

int janji(int p, int q, int t) {
	//cout << p << " " << q << " " << t << "\n";
	if (p == q) {
		return t;
	} else if (t % 2 == 1) {
		return 2 + janji(p + 1, q, t + 1);
	} else {
		return 2 + janji(p, q - 1, t + 1);
	}
}

int main()
{
	/*
	int a = 1, b = 1;
	for (int i = 2; i <= 7; i++) {
		b += a;
		a = b - a;
	}
	cout << b << "\n";

	cout << ayam(5, 6) << "\n";
	bebek(6, 7);

	empat();

	kambing(117);

	cout << kucing(2, 10);

	hitung(20, 56);

	telor(1, 2, 3);

	//cout << janji(20, 8, 0) << "\n";
	cout << janji(8, 16, 3) << "\n";
	*/


	cout << (1 << 0) << "\n";
}
