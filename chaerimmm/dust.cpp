#include <iostream>
#include <cstring>  //memcpy
#include <vector>

using namespace std;

const int MAX = 50 ;

int r, c, t;
int map[MAX][MAX];
int airCleanT = -1;
int airCleanB;

int ans;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1 ,-1 ,0 ,0 };

void dust() {
	int dust[MAX][MAX] = { 0 };

	memcpy(dust, map, sizeof(map));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] >= 5) {
				int d = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < r && 0 <= ny && ny < c && map[nx][ny] != -1 ) {
						dust[nx][ny] += d;
						dust[i][j] -= d;
					}
				}
			}
		}
	}
	memcpy(map, dust, sizeof(dust));
}

void clean() {
	for (int i = 1; i < c; i++)    map[airCleanT][i+1] = map[airCleanT][i];  // ->
	for (int i = 0; i < airCleanT; i++) map[i][c-1] = map[i+1][c-1];  // ^


	
}

void solve() {
	for (int i = 0; i < t; i++) {
		dust();
		clean();
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == -1 ) {
				airCleanT = i;
				airCleanB = i + 1;
			}
		}
	}

	solve();
	return 0;
}






