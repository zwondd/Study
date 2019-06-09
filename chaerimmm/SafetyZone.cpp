// �������� �ִ밳�� (for������ ���峷�������� ������-1���� ���� ���ؼ� ã�ƾߵ�)
#include <iostream>
#include <vector>
#include <string.h> 
#include <algorithm>  // min max �Լ� ��� 

using namespace std;

int N;
int lowest = 101;
int highest = 0;
int ans = 1;
int zone[101][101];
bool safeCheck[101][101];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void DFS(int x, int y, int h) {
	if (x < 0 || y < 0 || x >= N || y >= N) return; // ���� �����
	if (zone[x][y] <= h) return;  //������ ���� ���ϸ� ���
	if (safeCheck[x][y]) return;  //�湮�Ѿֵ�

	safeCheck[x][y] = true;

	//�����¿�Ž��
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i];
		int nY = y + dy[i];
		DFS(nX, nY, h);
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> zone[i][j];
			lowest = min(lowest, zone[i][j]);
			highest = max(highest, zone[i][j]);
		}
	}

	for (int h = lowest; h < highest; h++) {
		memset(safeCheck, false, sizeof(safeCheck));
		int cnt = 0;

		for (int i = 1; i <= N; i++) {	
			for (int j = 1; j <= N; j++) {
				if (!safeCheck[i][j] && zone[i][j] > h) {
					DFS(i, j, h);
					cnt++;
				}
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans << '\n';
	
	return 0;
}

