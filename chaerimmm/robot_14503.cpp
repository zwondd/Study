#include <iostream>
#include <queue>
#define MAX 51;
using namespace std;

int N, M;
int r, c, d;
int MAP[51][51];
int rslt;
int dir[4] = { 3,2,1,0 };  // ¼­:3, ³²:2, µ¿:1, ºÏ:0

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}

int main() {
	input();

	while (1) {
		if (MAP[r][c] == 0) {
			MAP[r][c] = 2;
			rslt++;
		}

		int check = 0;
		for (int i = 0; i < 4; i++) {
			d = d - 1;
			if (d < 0) {
				d = 3;
			}
			int temp_r = r + dx[d];
			int temp_c = c + dy[d];

			if (MAP[temp_r][temp_c] == 0) {
				r = temp_r;
				c = temp_c;
				check = 1;
				break;
			}
		}

		if (check == 1) {
			continue;
		}
		
		int temp_d = d - 2;
		if (temp_d == -2) {
			temp_d = 2;
		}
		if (temp_d == -1) {
			temp_d = 3;
		}

		r = r + dx[temp_d];
		c = c + dy[temp_d];

		if (MAP[r][c] == 1) {
			break;
		}
	}
	cout << rslt;
}