#include <iostream>
#include <vector>
#include <string>

#pragma warning(disable:4996)

using namespace std;

int main() {
	int m;
	cin >> m;
	while (m > 0) {
		int x, y;
		cin >> x >> y;
		string s;

		cin >> s;

		int U = 0, D = 0, L = 0, R = 0;

		int n = s.length();

		for (int i = 0; i < n; i++) {
			if (s[i] == 'U') U++;
			else if (s[i] == 'D') D++;
			else if (s[i] == 'L') L++;
			else if (s[i] == 'R') R++;

		}
		bool ans = true;

		if (x < 0) {
			ans = ans && (abs(x) <= L);	//дивлюся чи це число менше за кількість команд
			//нашо (якщо хоча б одна умова буде false ans буде 0
		}
		else {
			ans = ans && (x <= R);
			//дивимось щоб к-ть команд вправо була більшою за наш ікс
		}

		if (y < 0) {
			ans = ans && (abs(y) <= D);
		}
		else {
			ans = ans && (y <= U);
		}

		if (ans) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		m--;
	}
	return 0;
}