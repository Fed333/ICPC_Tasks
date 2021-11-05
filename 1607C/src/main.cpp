#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;

const long long INF = 1000000000000;

int main() {

	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		vi a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long dif = 0;
		long long min = a[0];
		long long next_min = -INF;
		long long max_min = min;
		for (int i = 1; i < n; ++i) {
			
			min = (long long)a[i - 1] - dif;
			next_min = (long long)a[i] - dif;
			max_min = max(max_min, min);
			
			dif += min;
		}
		if ((next_min - min) > min) {
			max_min = max(max_min, next_min - min);
		}

		cout << max_min << endl;
		--t;
	}
	
}
