// 19.06.30
// 백준 #14503 : 로봇 청소기

#include <iostream>

using namespace std;

int N, M;
int r, c, d;
int map[60][60];

int cleaned[60][60];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt=0;

void dfs(int x, int y, int d) {
    int nx, ny, cd;
    cd = d;
    // cout<<"x : "<<x<<" y : "<<y<<" d : "<<d<<endl;

    if ( !cleaned[x][y] ) {
        cleaned[x][y] = 1;
        cnt++;
    }

    for(int i=0; i<4; i++) {
        cd = (cd+3)%4;
        nx = x + dx[cd];
        ny = y + dy[cd];

        if ( nx<0 || nx>=N || ny<0 || ny>=M || map[nx][ny] ) continue;
        if ( cleaned[nx][ny] ) continue;

        dfs(nx,ny, cd);
        return;  // 청소할 곳 있으면 이동 후 return 
    }

    cd = (d+2)%4;
    nx = x + dx[cd];
    ny = y + dy[cd];

    if ( nx<0 || nx>=N || ny<0 || ny>=M || map[nx][ny] ) return;

    dfs(nx, ny, d);
}

int main() {

    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }

    dfs(r,c,d);
    cout<<cnt;
}