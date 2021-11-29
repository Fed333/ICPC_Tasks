#include <iostream>
#include <vector>

using namespace std;
//к-ть вершин, та номер шуканої вершини
int n, t;
bool flag = false;
//масив чисел по яким обраховуються ребра
vector<int> a;
//список суміжності
vector<vector<int>> list;

void dfs(int v) {
	for (int i = 0; i < list[v].size(); ++i) {
		int to = list[v][i];
		if (to == t) {
			flag = true;
			return;
		}
		dfs(list[v][i]);
	}
}

int main() {
	cin >> n >> t;
	list.resize(n + 1);
	a.resize(n, 0);
	//починаємо з одиниці щоб усунути проблему з нумерацією
	for (int i = 1; i < a.size(); ++i) {
		cin >> a[i];
	}
	//побудуємо список суміжностей
	int v;
	for (int i = 1; i < list.size() - 1; ++i) {
		v = i + a[i];			//вираховуємо вершину в яку заходить ребро
		list[i].push_back(v);	//додаємо ребро  до списку суміжностей
	}
	dfs(1);
	if (flag) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}