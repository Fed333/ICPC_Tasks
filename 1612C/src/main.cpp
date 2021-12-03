#include <cstdio>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

inline long long min(long long a, long long b) { return a < b ? a : b; }

long long emoutCount(int k, int i) {
	long long total = 2 * (long long)k - 1;
	long long n = min(i, k), d = 1, a1 = 1;
	long long S1 = 0, S2 = 0;
	long long an = a1 + (n-1)*d;
	S1 = (a1 + an) * n / 2;
	if (i > k) {
		a1 = an - 1;
		n = i - k;
		d = -1;
		an = a1 + (n - 1) * d;
		S2 = (a1 + an) * n / 2;
	}
	return S1 + S2;

}

int main() {
	int t;
	freopen("tests.txt", "r", stdin);
	
#ifndef DEBUG
	freopen("results.txt", "w", stdout);
	scanf("%d", &t);
	while (t > 0) {
		int k;
		long long x, c = 0, e = 0;
		scanf("%d%lld", &k, &x);
		long long l = 1, r = 2 * k - 1;
		long long m = 0;
		bool coincidence = false;
		while (l <= r) {
			m = ceil((r + l) / 2);
			c = emoutCount(k, m);
			if (c == x) {
				coincidence = true;
				break;
			}
			else if (c < x) {
				l = m + 1;
				
				
			}
			else {
				r = m - 1;
				
			}
		}
		if (!coincidence) {
			long long c1 = emoutCount(k, m);
			long long c2 = emoutCount(k, m + 1);
			if (c1 >= x) {
				m = m;
			}
			else {
				m = min(m + 1, 2*k-1);
			}
		}
		printf("%lld\n", m);
		--t;
	}
#else
	freopen("debug.txt", "w", stdout);
	int k = 5;
	for (int i = 1; i <= 2*k-1; ++i) {
		printf("%lld\n", emoutCount(k, i));
	}

#endif
	return 0;
}