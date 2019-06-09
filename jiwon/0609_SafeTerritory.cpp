// 19.06.09
// 백준 #2468 : 안전영역
// DFS 방식

#include <iostream>
using namespace std;

int N;
const int MAX=100;
int map[MAX+1][MAX+1]={0,};
int visited[MAX+1][MAX+1]={0,};

int floodHeight;
int maxHeight=0;
int minHeight=9999;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void input() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
            minHeight = (minHeight>map[i][j]) ? map[i][j] : minHeight;
            maxHeight = (maxHeight<map[i][j]) ? map[i][j] : maxHeight; 
        }
    }
    // cout<<"max height : "<<maxHeight<<endl;
}

void init() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            visited[i][j]=0;
        }
    }
}

void dfs(int x, int y) {
    int nx,ny;
    visited[x][y]=1;

    for(int i=0; i<4; i++) {
        nx=x+dx[i];
        ny=y+dy[i];

        if( nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && map[nx][ny]>floodHeight) {
            dfs(nx,ny);
        }
    }
}

int solve() {
    int cnt=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N ;j++) {
            if( !visited[i][j] && map[i][j]>floodHeight ) {
                cnt++;
                dfs(i,j); 
            }
        }
    }
    // cout<<"cnt : "<<cnt<<endl;
    return cnt;
}

int main(void) {
    int maxTerritroy=0;
    int tmp;
    input();

    for(int h=minHeight; h<=maxHeight; h++) {
        init();
        floodHeight=h;
        tmp=solve();
        maxTerritroy=( maxTerritroy < tmp ) ? tmp : maxTerritroy;
    }

    return 0;
}