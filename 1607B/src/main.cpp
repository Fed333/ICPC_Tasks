#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

inline long long sum_n(long long a1, long long d, long long n) {
	return (2 * a1 + d * (n - 1)) * n / 2;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t > 0) {
		long long x0, n;
		scanf("%lld %lld", &x0, &n);
		long long i = 1;

		int sign = x0%2 == 0?1:-1;	//визначити знак

		long long D;
		long long mod = n % 4;
		if (mod == 1) {
			D = -n;
		}
		else if (mod == 2) {
			D = 1;
		}
		else if (mod == 3) {
			D = n + 1;
		}
		else {
			D = 0;
		}
		long long s = x0 + sign * D;
		printf("%lld\n", s);
		--t;
	}
	return 0;
}