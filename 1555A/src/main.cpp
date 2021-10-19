#include <cstdio>


#pragma warning(disable:4996)

typedef long long ll;

inline ll max(ll a, ll b) {
	return a > b ? a : b;
}


int main() {
	int t;
	scanf("%d", &t);
	while (t > 0) {
		long long n;
		scanf("%lld", &n);
		if (n % 2 != 0) {
			++n;
		}
		long long a = max( (long long)(n * 5 / 2), (long long)15);
		printf("%lld\n", a);
		--t;
	}
	return 0;
}