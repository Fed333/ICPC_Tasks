#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;

#define WAY1 true

int main() {
	int t;
	freopen("tests.txt", "r", stdin);
	freopen("results.txt", "w", stdout);
	scanf("%d", &t);
	while (t > 0) {
		int n, l, r;
		long long k;
		scanf("%d%d%d%lld", &n, &l, &r, &k);
		vi arr(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
#ifdef WAY1
		sort(arr.begin(), arr.end());
#endif

		long long prev = arr[0]; int count = 0;
		for (int i = 0; i < n; ++i) {
			long long el = arr[i];
#ifdef WAY1
			if (el >= l && el <= r) {
				if (k >= el) {
					k -= el;
					count++;
				}
			}
		}
#else
			if (el >= l && el <= r) {
				if (el < prev) {
					k += prev - el;
				}
				if (k >= el) {
					k -= el;
					count++;
					prev = max(el, prev);
				}
			}
		}
#endif
		printf("%d\n", count);

		--t;
	}
	return 0;
}