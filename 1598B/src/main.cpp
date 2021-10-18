#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>


#pragma warning(disable:4996)

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<set<int>> vsi;


int main() {
	int t;

	scanf("%d", &t);
	getchar();

	while (t > 0) {
		int n;
		scanf("%d", &n);
		getchar();
		vsi days(5, si());
		si u;	//універсальна множина студентів
		for (int i = 0; i < n; ++i) {
			
			u.insert(i);
			for (int j = 0; j < 5; ++j) {
				int n;
				scanf("%d", &n);
				if (n == 1) {
					days[j].insert(i);
				}
			}
			getchar();
		}
		
		bool found = false;
		for (int i = 0; i < 5; ++i) {
			for (int j = i; j < 5; ++j) {
				if (i != j) {
					si a = days[i];
					si b = days[j];
					
					si un;
					set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(un, un.begin()));
					si in;
					set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(in, in.begin()));
					si dif;	//група студентів які не вибрали ні день a ні день b
					set_difference(u.begin(), u.end(), un.begin(), un.end(), std::inserter(dif, dif.begin()));
					


					//якщо такої групи немає, отже можна спробувати поділити всіх на дві групи
					if (dif.size() == 0){
						si d1;
						si d2;
						set_difference(a.begin(), a.end(), in.begin(), in.end(), inserter(d1, d1.begin()));
						set_difference(b.begin(), b.end(), in.begin(), in.end(), inserter(d2, d2.begin()));
						if (d1.size() <= n / 2 && d2.size() <= n / 2) {
							found = true;
							break;
						}
					}
				}
			}
		}

		if (found) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		//for (int i = 0; i < days.size(); ++i) {
		//	for (set<int>::iterator it = days[i].begin(); it != days[i].end(); it++) {
		//		printf("%d ", *it);
		//	}
		//	printf("\n");
		//}

		--t;
	}

	return 0;
}