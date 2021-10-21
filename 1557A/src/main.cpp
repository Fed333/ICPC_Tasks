#include <algorithm>
#include <vector>
#include <cstdio>

#pragma warning(disable:4996)
 

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);

	while (t > 0) {
		
		int n;
		scanf("%d", &n);
	
		vi seq(n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &seq[i]);
			sum += seq[i];
		}

		int max = seq[0];

		for (int i = 0; i < n; ++i) {
			if (seq[i] > max) {
				max = seq[i];
			}
		}
		
		double fa = max;
		double fb = ((double)(sum - fa)) / ((double)n - 1);
		double res = fa + fb;


		printf("%.7lf\n", (fa + fb));

		--t;
	}

	return 0;
}