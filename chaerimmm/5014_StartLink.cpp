#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000 + 1;

int F, S, G, U, D;
int dist[MAX];


int bfs(void) {
	queue<int> q;
	q.push(S);
	dist[S] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
        //����
		if (curr == G) {
			return dist[curr] - 1;
		}
		else {
			return -1;
		}

		//������
		int next[2] = { curr + U, curr - D };
		for (int i = 0; i < 2; i++) {
			//���� ���� ����, �̹̰��� �ƴѰ� 
			if (1 <= next[i] && next[i] <= F && dist[next[i]] == 0) {
				q.push(next[i]); 
				dist[next[i]] = dist[curr] + 1;
			}
		}
	}
	
}
				

int main(void) {
	scanf_s("%d %d %d %d %d", &F, &S, &G, &U, &D);
	bfs();

	if (bfs() == -1) {
		printf("use the stairs");
	}
	else {
		printf("%d", bfs());
	}
	return 0;
}