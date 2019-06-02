#include <iostream>
#include <queue>
#include <vector>


using namespace std;

struct chess {
	int x, y;
};

int n, sx, sy, ex, ey;
int d[300][300]; 
const int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void bfs() {
	queue<chess> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (x == ex && y == ey) {
			printf("%d\n", d[x][y]);
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}
			if (d[nx][ny]) {
				continue;
			}
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	int t;
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		scanf_s("%d %d", &sx, &sy);
		scanf_s("%d %d", &ex, &ey);
		memset(d, 0, sizeof(d));
		bfs();
	}
	return 0;
}

