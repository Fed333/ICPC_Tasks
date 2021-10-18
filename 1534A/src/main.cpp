#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while (t > 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		getchar();

		vvc flag(n, vc(m, '.'));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char symb;
				scanf("%c", &symb);
				flag[i][j] = symb;
			}
			getchar();
		}


		int pos[][2] = { {0, 1}, {1, 0} };	//0 - для R, 1 - для L
		bool established = false;
		bool paint = true;
		for (int i = 0; i < n; ++i) {
			int parity_row = i % 2;
			for (int j = 0; j < m; ++j) {
				int parity_collumn = j % 2;
				char s = flag[i][j];
				if (!established) {
					if (s == 'R') {
						
						pos[0][parity_row] = parity_collumn;
						pos[1][(parity_row + 1) % 2] = parity_collumn;
						pos[1][parity_row] = parity_collumn == 1 ? 0 : 1;
						pos[0][(parity_row + 1) % 2] = pos[1][parity_row];
						established = true;
					}
					else if (s == 'W') {
						
						pos[1][parity_row] = parity_collumn;
						pos[0][(parity_row + 1) % 2] = parity_collumn;
						pos[0][parity_row] = parity_collumn == 1 ? 0 : 1;
						pos[1][(parity_row + 1) % 2] = pos[0][parity_row];
						established = true;
					}
					
				}
				else {
					if (s == 'R' && pos[0][parity_row] != parity_collumn) {
						paint = false;
					}
					else if (s == 'W' && pos[1][parity_row] != parity_collumn) {
						paint = false;
					}
				}
			}
		}
		if (paint) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				int parity_row = i % 2;
				for (int j = 0; j < m; ++j) {
					char s;
					if (j%2 == 0) {
						//який символ друкувати на місці парного індекса рядка i
						s = pos[0][parity_row] == 0 ? 'R' : 'W';
					}
					else {
						s = pos[1][parity_row] == 0 ? 'R' : 'W';
					}
					printf("%c", s);
				}
				printf("\n");
			}
		}
		else {
			printf("NO\n");
		}

		--t;
	}

	return 0;
}