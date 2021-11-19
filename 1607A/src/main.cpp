#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

typedef unordered_map<char, int> um;

int main() {

	int t;
	scanf("%d", &t);
	while (t > 0) {
		char buf[51];
		char alphabet[27];
		getchar();
		scanf("%s", alphabet);
		scanf("%s", buf);

		um keyboard;
		for (int i = 0; i < strlen(alphabet); ++i) {
			keyboard[alphabet[i]] = (i + 1);
		}

		int sum = 0;
		for (int i = 1; i < strlen(buf); ++i) {
			char curr = buf[i];
			char prev = buf[i - 1];
			if (curr != prev) {
				sum += abs(keyboard[curr] - keyboard[prev]);
			}
		}
		printf("%d\n", sum);
		--t;
	}
	return 0;
}