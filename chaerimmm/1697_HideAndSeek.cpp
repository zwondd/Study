#include <iostream>
#include <queue>

using namespace std;

struct node {
	int p;
	int cnt;
};

const int MAX = 1000000;
int sx, ex;
int n, k; //¼öºó µ¿»ý
int dist[MAX + 1];

void bfs() {
	queue<int> q;
	q.push(n);   // queue ¿¡ ³Ö¾îÁÜ
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == k) {
			printf("%d\n", dist[x]);
			return;
		}

		for (int nx : {x-1, x+1, 2*x}) {
			if (nx < 0 || nx > MAX) {
				continue;
			}
			if (dist[nx]) {
				continue;
			}
			q.push(nx);
			dist[nx] = dist[x] + 1;
		}
	}
}


int main() {
	scanf_s("%d %d", &n, &k);
	bfs();
	return 0;
}