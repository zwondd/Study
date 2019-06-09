// 19.06.09
// 제한시간 : 1시간
// 백준 #1012 : 유기농 배추

#include <iostream>
using namespace std;

int T, M, N, K;  // M : 가로 , N : 세로
const int MAX = 50;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int map[MAX+1][MAX+1]={0,};
int visited[MAX+1][MAX+1]={0,};

int cnt=0;

void init()
{
    cnt=0;

    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            map[i][j]=0;
            visited[i][j]=0;
        }
    }
}

void input()
{
    cin>>M>>N>>K;
    for(int i=0; i<K; i++)
    {
        int x,y;
        cin>>x>>y;
        map[x][y]=1;
    }
}

void dfs(int x, int y)
{
    int nx,ny;
    visited[x][y]=1;

    for(int i=0; i<4; i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<M && map[nx][ny] && !visited[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}

int main(void)
{
    int res[100000];

    cin>>T;
    for(int i=0; i<T; i++)
    {
        init();
        input();
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                if(map[j][k] && !visited[j][k])
                {
                    cnt++;
                    dfs(j,k);
                }
            }
        }
        res[i]=cnt;
    }

    for(int i=0; i<T; i++)
        cout<<res[i]<<endl;
}