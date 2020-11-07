#include <bits/stdc++.h>
using namespace std;

bool cek(string str) { 
    for (int i = 0; i < str.length() - 1; i++) { 
        for (int j = i + 1; j < str.length(); j++) { 
            if (str[i] == str[j]) { 
                return false; 
            } 
        } 
    }
	cout << str << "\n"; 
    return true; 
} 

int main() {
	ios_base::sync_with_stdio(0);
	int year;
	cin >> year;
	for (int i = year+1; i <= 9999; i++) {
		stringstream ss;
		string s;
		ss << i;
		ss >> s;
		if (cek(s)) {
			exit(0);
		}
	}
}
