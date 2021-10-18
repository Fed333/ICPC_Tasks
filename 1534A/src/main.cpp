#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

#ifdef DEBUG
int main() {

	int t;
	scanf("%d", &t);
	getchar();
	while (t > 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		getchar();

		vvc flag(n+2, vc(m, '.'));
		for (int i = 1; i < n+1; ++i) {
			for (int j = 0; j < m; ++j) {
				char symb;
				scanf("%c", &symb);
				flag[i][j] = symb;
			}
			getchar();
		}
		
		bool paint = true;
		for (int i = 1; i < n+1 && paint; ++i) {

			for (int j = 1; j < m - 1; ++j) {
				char s = flag[i][j];
				if (s == 'R') {
					if (flag[i][j - 1] != 'R' && flag[i][j + 1] != 'R' && flag[i + 1][j] != 'R' && flag[i-1][j] != 'R') {
						flag[i][j - 1] = flag[i][j + 1] = flag[i + 1][j] = flag[i-1][j] = 'W';
					}
					else {
						paint = false;
					}
				}
				else if (s == 'W') {
					if (flag[i][j - 1] != 'W' && flag[i][j + 1] != 'W' && flag[i + 1][j] != 'W' && flag[i-1][j] != 'W') {
						flag[i][j - 1] = flag[i][j + 1] = flag[i + 1][j] = flag[i-1][j] = 'R';
					}
					else {
						paint = false;
					}
				}
				else {
					flag[i][j] = (flag[i][j - 1] == 'R') ? 'W' : 'R';
					flag[i][j+1] = (flag[i][j] == 'R') ? 'W' : 'R';
				}	
			}

		}

		if (paint) {
			printf("YES\n");
			for (int i = 1; i < n+1; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%c", flag[i][j]);
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
#endif

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

		//for (int i = 0; i < 2; ++i) {
		//	for (int j = 0; j < 2; ++j) {
		//		printf("%d ", pos[i][j]);
		//	}
		//	printf("\n");
		//}
		--t;
	}

	return 0;
}