// 19.06.01
// 제한시간 : 1시간
// 백준 #16236 : 아기상어
// BFS 방식

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX = 20;

int N;
int map[MAX+1][MAX+1];
int visit[MAX+1][MAX+1];
int shark_size = 2;
int eat_cnt=0;

int start_pos[2];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int time=0;

typedef struct POS{
    int x, y, dist;
}POS;

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if( map[i][j] == 9 )
            {
                map[i][j]=0;
                start_pos[0]=i;
                start_pos[1]=j;
            }
        }
    }
}

void init()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            visit[i][j]=0;
        }
    }   
}

void bfs()
{
    int x, y, nx, ny;
    cout<<"bfs"<<endl;

    queue<POS> q;
    POS cur = {start_pos[0], start_pos[1], 0};
    q.push(cur);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        x= cur.x;
        y= cur.y;
        cout<<"x : "<<x<<" y: "<<y<<" dist : " <<cur.dist<<" map: "<<map[x][y]
        <<" shark size : "<<shark_size<<endl;

        if( map[x][y]>0 && map[x][y] < shark_size )
        {
            map[x][y] = 0;
            eat_cnt++;
            time=cur.dist;

            cout<<"cur.dist : "<<cur.dist<<endl;


            if( eat_cnt == shark_size )
            {
                shark_size++;
                eat_cnt=0;
            }

            // 초기화
            while(!q.empty()) q.pop();
            for(int i=0; i<N; i++)
                memset(visit[i],0,sizeof(visit[i]));
                
            visit[x][y] = 1;
        }

        for(int i=0; i<4; i++)
        {
            nx=x+dx[i];
            ny=y+dy[i];

            if( nx>=0 && nx<N && ny>=0 && ny<N && !visit[nx][ny] && map[nx][ny]<=shark_size  )
            {
                POS next={nx,ny,cur.dist+1};
                visit[nx][ny]=1;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    input();
    bfs();
    cout<<"time : "<<time<<endl;

    return 0;
}