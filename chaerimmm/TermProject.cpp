#include <iostream>
using namespace std;

int T, n;
int stu[100001];
bool visited[100001];
bool team[100001];
int memCnt;
int rslt[999];

void DFS(int n) {
	
	visited[n] = true; 
	
	int next = stu[n];
	cout << "start : " << n << " next : " << next << endl;
	if (visited[next]) { 
		if (!team[next]) {
			for (int i = next; i != n; i = stu[i]) {
				memCnt++;
				cout << "Cnt : " << memCnt << endl;
			}
			memCnt++;
			cout << memCnt << endl;
		}
	}
	else {
		DFS(stu[n]);
	}
	team[n] = true;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		
		memset(visited, 0, sizeof(visited));
		memset(team, 0, sizeof(team));
		memCnt = 0;

		for (int i = 1; i <= n; i++) {
			cin >> stu[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}

		rslt[i] = n - memCnt;
		
	}
	for (int j = 0; j < T; j++) {
		cout << rslt[j] << '\n';
	}
}

