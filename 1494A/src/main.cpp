#include <cstdio>
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

bool subseq(char* s, char A, char B, char C) {
	bool check = true;
	int op = 0, cl = 0, l = strlen(s);

	for (int i = 0; s[i] != '\0' && check; ++i) {
		char b;
		switch (s[i]) {
		case 'A': b = A; break;
		case 'B': b = B; break;
		case 'C': b = C; break;
		}

		if (b == '(') {
			if (op >= l/2) {
				check = false;
			}
			else {
				op++;
			}
		}
		else if (b == ')') {
			if (op <= cl) {
				check = false;
			}
			else {
				cl++;
			}
		}

	}
	return check;
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while(t > 0) {
		char str[50];
		bool check = false;
		scanf("%s", str);
		for (int i = 0; i < 2 && !check; ++i) {
			for (int j = 0; j < 2 && !check; ++j) {
				for (int k = 0; k < 2 && !check; ++k) {
					check = subseq(str, '(' + i, '(' + j, '(' + k);
				}
			}
		}

		if (check) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		--t;
	}
	return 0;
}
