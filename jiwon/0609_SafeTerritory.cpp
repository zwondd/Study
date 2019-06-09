// 19.06.09
// 백준 #2468 : 안전영역
// DFS 방식

#include <iostream>
using namespace std;

int N;
const int MAX=100;
int map[MAX+1][MAX+1]={0,};
int visited[MAX+1][MAX+1]={0,};

int height[101]={0,};
int floodHeight;
int maxHeight=0;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            
            maxHeight = (maxHeight<map[i][j]) ? map[i][j] : maxHeight; 
        }
    }
    // cout<<"max height : "<<maxHeight<<endl;
}

void init()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            visited[i][j]=0;
        }
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

        if( nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && map[nx][ny]>floodHeight)
        {
            dfs(nx,ny);
        }
    }
}

int solve()
{
    int cnt=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N ;j++)
        {
            if( !visited[i][j] && map[i][j]>floodHeight )
            {
                cnt++;
                dfs(i,j); 
            }
        }
    }
    // cout<<"cnt : "<<cnt<<endl;
    return cnt;
}

int main(void)
{
    int maxTerritroy=0;
    int tmp;
    input();

    for(int i=0; i<=maxHeight; i++)
    {
        init();
        floodHeight=i;
        height[floodHeight]=1;
        // cout<<"height : "<<floodHeight<<endl;
        tmp=solve();
        maxTerritroy=( maxTerritroy < tmp ) ? tmp : maxTerritroy;
    }


    // for(int i=0; i<N; i++)
    // {
    //     for(int j=0; j<N; j++)
    //     {
    //         if( !height[map[i][j]] )
    //         {
    //             init();
    //             floodHeight=map[i][j];
    //             height[map[i][j]]=1;
    //             cout<<"height : "<<map[i][j]<<endl;
    //             tmp=solve();
    //             maxTerritroy=( maxTerritroy < tmp ) ? tmp : maxTerritroy;
    //         }
    //     }
    // }
    cout<<maxTerritroy;

    return 0;
}