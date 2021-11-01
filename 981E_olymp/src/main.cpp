#include <cstdio>
#include <vector>

#pragma warning (disable:4996)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

const int INF = 1000000000;

vvi graph;	//матриця суміжності
vi used;	//пофарбовані вершини
vi min_e;	//масив з мінімальними дугами для вершин
vi ends; //масив з кінцями найменших дуг(тобто з вершинами куди веде дуга яка для вершини i(індекс) є найменшою)

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	graph.assign(n, vi(n, INF));
	used.assign(n, false);
	min_e.assign(n, INF);
	ends.assign(n, -1);

	int len = 0;	//довжина остовного дерева 

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a - 1][b - 1] = c;
		graph[b - 1][a - 1] = c;
	}
	
	for (int i = 0; i < n; ++i) {

		// v - це перша вершина(на першій ітерації може бути любою)
		int v = -1; //це такий політичний трюк, який поможе нам вибрати першу вершину без болісно

		for (int j = 0; j < n; ++j) {
			if (!used[j] && (v == -1 || min_e[v] > min_e[j])) {
				v = j;	//найдена оптимальніша вершина
			}
		}
		used[v] = true;		//фарбуємо її тут
		if (ends[v] != -1) {
			len += min_e[v];
		}
		//а тепер вибрати другу вершину
		//to - вершина в яку веде дуга(наша друга вершина)

		for (int to = 0; to < n; ++to) {
			if (graph[v][to] < min_e[to]) {
				min_e[to] = graph[v][to];	//поступово ваги для ребер суміжних з остовом прощитуємо тут
				ends[to] = v;
			}
		}

	
	}

	printf("%d\n", len);


	return 0;
}