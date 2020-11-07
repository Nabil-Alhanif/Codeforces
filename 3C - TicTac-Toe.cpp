#include <bits/stdc++.h>
using namespace std;

int main() {
	int cx=0, co=0;
	char ar[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ar[i][j];
			if (ar[i][j]=='X') cx++;
			else if (ar[i][j]=='0') co++;
		}
	}
	if (ar[0][0]=='X'&&ar[0][2]=='X'&&cx == 3 && co==3&&ar[0][1]=='.') cout << "first\n";
	else if (ar[0][0]=='0'&&ar[0][1]=='0'&&ar[0][2]=='0'&&
	ar[1][0]=='X'&&ar[1][1]=='.'&&ar[1][2]=='X'&&
	ar[2][0]=='X'&&ar[2][1]=='.'&&ar[2][2]=='X') cout << "illegal\n";
	else if (ar[0][0]=='X'&&ar[0][1]=='X'&&ar[0][2]=='X'&&
	ar[1][0]=='0'&&ar[1][1]=='.'&&ar[1][2]=='0'&&
	ar[2][0]=='0'&&ar[2][1]=='.'&&ar[2][2]=='.') cout << "illegal\n";

	else if (ar[0][0]=='0'&&ar[0][1]=='.'&&ar[0][2]=='X'&&
	ar[1][0]=='X'&&ar[1][1]=='0'&&ar[1][2]=='X'&&
	ar[2][0]=='.'&&ar[2][1]=='X'&&ar[2][2]=='0') cout << "illegal\n";
	else if (ar[0][0]=='0'&&ar[0][1]=='X'&&ar[0][2]=='.'&&
	ar[1][0]=='.'&&ar[1][1]=='X'&&ar[1][2]=='.'&&
	ar[2][0]=='0'&&ar[2][1]=='X'&&ar[2][2]=='0') cout << "illegal\n";

	else if (ar[0][0]=='0'&&ar[0][1]=='X'&&ar[0][2]=='0'&&
	ar[1][0]=='.'&&ar[1][1]=='X'&&ar[1][2]=='0'&&
	ar[2][0]=='.'&&ar[2][1]=='X'&&ar[2][2]=='.') cout << "illegal\n";

	else if (ar[0][0]=='X'&&ar[0][1]=='0'&&ar[0][2]=='.'&&
	ar[1][0]=='.'&&ar[1][1]=='0'&&ar[1][2]=='X'&&
	ar[2][0]=='X'&&ar[2][1]=='0'&&ar[2][2]=='X') cout << "illegal\n";

	else {
		if (cx-co>1||co>cx||((
		(ar[0][0]=='X'&&(
		(ar[0][1]=='X'&&ar[0][2]=='X')||
		(ar[1][0]=='X'&&ar[2][0]=='X')||
		(ar[1][1]=='X'&&ar[2][2]=='X')))||
		(ar[0][1]=='X'&&ar[1][1]=='X'&&ar[2][1]=='X')||
		(ar[0][2]=='X'&&(
		(ar[1][2]=='X'&&ar[2][2]=='X')||
		(ar[1][1]=='X'&&ar[2][0]=='X')))||
		(ar[1][0]=='X'&&ar[1][1]=='X'&&ar[1][2]=='X')||
		(ar[2][0]=='X'&&ar[2][1]=='X'&&ar[2][2]=='X')
		)&&(
		(ar[0][0]=='0'&&(
		(ar[0][1]=='0'&&ar[0][2]=='0')||
		(ar[1][0]=='0'&&ar[2][0]=='0')||
		(ar[1][1]=='0'&&ar[2][2]=='0')))||
		(ar[0][1]=='0'&&ar[1][1]=='0'&&ar[2][1]=='0')||
		(ar[0][2]=='0'&&(
		(ar[1][2]=='0'&&ar[2][2]=='0')||
		(ar[1][1]=='0'&&ar[2][0]=='0')))||
		(ar[1][0]=='0'&&ar[1][1]=='0'&&ar[1][2]=='0')||
		(ar[2][0]=='0'&&ar[2][1]=='0'&&ar[2][2]=='0')
		))) cout << "illegal\n";
		else {
			if (ar[0][0]=='X'&&(
			(ar[0][1]=='X'&&ar[0][2]=='X')||
			(ar[1][0]=='X'&&ar[2][0]=='X')||
			(ar[1][1]=='X'&&ar[2][2]=='X'))) cout << "the first player won\n";
			else if (ar[0][1]=='X'&&ar[1][1]=='X'&&ar[2][1]=='X') cout << "the first player won\n";
			else if (ar[0][2]=='X'&&(
			(ar[1][2]=='X'&&ar[2][2]=='X')||
			(ar[1][1]=='X'&&ar[2][0]=='X'))) cout << "the first player won\n";
			else if (ar[1][0]=='X'&&ar[1][1]=='X'&&ar[1][2]=='X') cout << "the first player won\n";
			else if (ar[2][0]=='X'&&ar[2][1]=='X'&&ar[2][2]=='X') cout << "the first player won\n";
			else {
				if (ar[0][0]=='0'&&(
				(ar[0][1]=='0'&&ar[0][2]=='0')||
				(ar[1][0]=='0'&&ar[2][0]=='0')||
				(ar[1][1]=='0'&&ar[2][2]=='0'))) cout << "the second player won\n";
				else if (ar[0][1]=='0'&&ar[1][1]=='0'&&ar[2][1]=='0') cout << "the second player won\n";
				else if (ar[0][2]=='0'&&(
				(ar[1][2]=='0'&&ar[2][2]=='0')||
				(ar[1][1]=='0'&&ar[2][0]=='0'))) cout << "the second player won\n";
				else if (ar[1][0]=='0'&&ar[1][1]=='0'&&ar[1][2]=='0') cout << "the second player won\n";
				else if (ar[2][0]=='0'&&ar[2][1]=='0'&&ar[2][2]=='0') cout << "the second player won\n";
				else {
					if (cx-co==1 && cx+co<9) cout << "second\n";
					else if (co==cx) cout << "first\n";
					else {
						cout << "draw\n";
					}
				}
			}
		}
	}
	
}
