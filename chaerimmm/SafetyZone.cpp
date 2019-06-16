// 안전영역 최대개수 (for문으로 가장낮은점부터 높은점-1까지 개수 비교해서 찾아야됨)
#include <iostream>
#include <vector>
#include <string.h> 
#include <algorithm>  // min max 함수 사용 

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
	if (x < 0 || y < 0 || x >= N || y >= N) return; // 범위 벗어나면
	if (zone[x][y] <= h) return;  //강수량 높이 이하면 잠김
	if (safeCheck[x][y]) return;  //방문한애들

	safeCheck[x][y] = true;

	//상하좌우탐색
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

