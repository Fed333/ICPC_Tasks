#include <iostream>
#include <vector>
#include <algorithm>


typedef long l;
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	for (ll i = 0; i < m; ++i) {
		cin >> b[i];
	}


	//�� ���� �� ������ �������� ����� �� ��� ����� ��������� � ������� ��� ������ �� �������� (���� ��� ������ � �������)
	//(�� ������ ��� �������� ��� 1)
	for (int i = 1; i < a.size(); ++i) {
		a[i] -= a[0];
	}
	ll k;
	//���� ������ ����� ���������� � ������ �������� �������� ��� ���� �����, ������ ������ ������ �������
	if (n == 1) {
		k = 0;
	}
	else {
		k = a[1];
		//���������� ������ ��� ������ �, ��� ��������� � �������
		for (int i = 1; i < a.size(); ++i) {
			k = gcd(k, a[i]);
		}
	}
	//����� �� ������ ���������� ����� �������� ���� � ��� ������ ���������� � a[0]...a[n-1] + b[j]  
	//� ������ ������
	for (int i = 0; i < b.size(); ++i) {
		if (k == 1)
			cout << k << " ";
		else {
			ll g = gcd(k, b[i] + a[0]);
			cout << g << " ";
		}
	}


	return 0;
}