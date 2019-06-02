// 19.06.01
// 백준 #7562 : 나이트의 이동
// BFS 방식

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int tc;
int res[10000];
int dir_x[8]={2,1,-1,-2,-2,-1,1,2};
int dir_y[8]={1,2,2,1,-1,-2,-2,-1};

int length;
int cur[2];
int goal[2];

int solve(int x,int y)
{
    int visited[310][310]={0,};
    int depth[310][310]={0,};

    queue<pair<int,int>> q;
    
    pair <int,int> r = make_pair(x,y);
    q.push(r);

    while(!q.empty())
    {
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();

        if (cur_x==goal[0] && cur_y==goal[1])
        {
            return depth[goal[0]][goal[1]];
        }

        for(int i=0; i<8; i++)
        {
            int nx=cur_x+dir_x[i];
            int ny=cur_y+dir_y[i];
            if (nx>=0 && nx<length && ny>=0 && ny<length && !visited[nx][ny])
            {
                visited[nx][ny]=1;
                depth[nx][ny]=depth[cur_x][cur_y]+1;
                q.push(pair<int,int>(nx,ny));
            }
        }
    }
}

int main(void)
{
    cin>>tc;
    
    for(int i=0;i<tc;i++)
    {
        cin>>length;
        cin>>cur[0]>>cur[1];
        cin>>goal[0]>>goal[1];

        res[i]=solve(cur[0],cur[1]);
    }
    for(int i=0;i<tc;i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}