#include <iostream>
#include <vector>

using namespace std;
//�-�� ������, �� ����� ������ �������
int n, t;
bool flag = false;
//����� ����� �� ���� ������������� �����
vector<int> a;
//������ ��������
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
	//�������� � ������� ��� ������� �������� � ����������
	for (int i = 1; i < a.size(); ++i) {
		cin >> a[i];
	}
	//�������� ������ ����������
	int v;
	for (int i = 1; i < list.size() - 1; ++i) {
		v = i + a[i];			//���������� ������� � ��� �������� �����
		list[i].push_back(v);	//������ �����  �� ������ ����������
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