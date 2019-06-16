#include <iostream>
#include <vector>
#include <string.h> // �迭�ʱ�ȭ


using namespace std;

int T, M, N, K;
int board[51][51] = { 0, };
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void DFS(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N) return; //�� ���� �����
	if (board[x][y] != 1) return;  //�ƹ��͵� ������
	board[x][y] = 2;  //�湮ó��

	//�����¿�Ž��
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i];
		int nY = y + dy[i];
		DFS(nX, nY);
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		cin >> M >> N >> K;

		memset(board, 0, sizeof(board));

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		for (int a = 0; a < M; a++) {
			for (int b = 0; b < N; b++) {
				if (board[a][b] == 1) {
					DFS(a, b);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

