#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >> t;
	getchar();
	while (t > 0) {
		string str;
		getline(cin, str);
		
		if (str[0] != str[str.length() - 1]) {
			str[0] = str[str.length() - 1];
		}
		cout << str << endl;

		--t;
	}
	return 0;
}