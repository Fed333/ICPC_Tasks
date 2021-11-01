#include <cstdio>
#include <vector>


#pragma warning(disable:4996)

using namespace std;

const int INF = (int)1e9;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;	//матриц€ сум≥жност≥
//vvi m_c;	//матриц€ сполучень
vvi m_p;	//матриц€ шл€х≥в


int main() {
	int n;
	
	scanf("%d", &n);
	graph.assign(n, vi(n, -1));
	//m_c.assign(n, vi(n, -1));
	m_p.assign(n, vi(n, INF));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &graph[i][j]);
			m_p[i][j] = (graph[i][j] > -1)?graph[i][j]:INF;
			//m_c[i][j] = (graph[i][j] > -1) ? j : -1;
		}
		getchar();
		char s;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					int old_path = m_p[i][j];			//пр€мий шл€х, або ран≥ше знайдений
					int detour = m_p[i][k] + m_p[k][j];	//новий шл€х з обходом через k
					if (old_path > detour) {			//знайдено коротший шл€х
						m_p[i][j] = detour;
						//m_c[i][j] = k;
					}
				}
			}
		}
	}
	int d, r = INF;
	d = m_p[0][0];

	for (int i = 0; i < n; ++i) {
		int max_r = m_p[i][0];	//максимальне дл€ одного р€дка
	
		for (int j = 0; j < n; ++j) {
			if (d < m_p[i][j]) {
				d = m_p[i][j];
			}
			if (max_r < m_p[i][j]) {
				max_r = m_p[i][j];
			}
			//printf("%d ", m_p[i][j]);
		}
		if (r > max_r) {	//€кщо знайдене значенн€ менше за попереднЇ
			r = max_r;		//у нас новий рад≥ус
		}
		//printf("\n");
	}

	printf("%d\n%d\n", d, r);
	return 0;
}